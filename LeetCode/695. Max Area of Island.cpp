#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& grid,int r,int c){
        return r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]==1;
}
void dfs(vector<vector<int>>& grid,int r,int c,vector<vector<bool>>& visited,int& islandSize)
{
	islandSize++;
	cout<<r<<" "<<c<<" "<<islandSize<<endl;
    visited[r][c]=true;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    
    for(int i=0;i<4;i++)
    {
        if(isValid(grid,r+x[i],c+y[i]) && !visited[r+x[i]][c+y[i]])
        {
            dfs(grid,r+x[i],c+y[i],visited,islandSize);
        }
    }
}
int numIslands(vector<vector<int>>& grid) {
    vector<vector<bool>> visited;
    for(int i=0;i<grid.size();i++)
    {
        vector<bool> tmp(grid[0].size(),false);
        visited.push_back(tmp);
    }
    
    int islandCount=0;
    int ans=-1;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++){
            if(!visited[i][j] && grid[i][j]==1)
            {
            	int islandSize=0;
            	//cout<<"New Island "<<i<<" "<<j<<endl;
                islandCount++;
                dfs(grid,i,j,visited,islandSize);
                ans=max(ans,islandSize);
            }
        }
    }
    return ans;
}
    
int main(void)
{
	vector<vector<int>> grid={
	{1,0,0,1},
	{1,1,0,0},
	{1,0,1,1},
	{1,0,0,1},
	};
	cout<<numIslands(grid)<<endl;
	return 0;
}
