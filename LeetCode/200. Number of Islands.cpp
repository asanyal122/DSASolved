class Solution {
public:
    bool isValid(vector<vector<char>>& grid,int r,int c){
        return r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]=='1';
}
void dfs(vector<vector<char>>& grid,int r,int c,vector<vector<bool>>& visited)
{
	//cout<<r<<" "<<c<<endl;
    visited[r][c]=true;
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    
    for(int i=0;i<4;i++)
    {
        if(isValid(grid,r+x[i],c+y[i]) && !visited[r+x[i]][c+y[i]])
        {
            dfs(grid,r+x[i],c+y[i],visited);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    vector<vector<bool>> visited;
    for(int i=0;i<grid.size();i++)
    {
        vector<bool> tmp(grid[0].size(),false);
        visited.push_back(tmp);
    }
    
    int islandCount=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++){
            if(!visited[i][j] && grid[i][j]=='1')
            {
            	//cout<<"New Island "<<i<<" "<<j<<endl;
                islandCount++;
                dfs(grid,i,j,visited);
            }
        }
    }
    return islandCount;
}
};
