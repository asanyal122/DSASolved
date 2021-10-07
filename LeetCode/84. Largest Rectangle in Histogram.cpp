class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int> s;
        vector<int> nse(n);
        nse[n-1]=n;
        s.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                nse[i]=s.top();
            }
            else
            {
                nse[i]=n;
            }
            s.push(i);
        }
        return nse;
    }
    vector<int> prevSmaller(vector<int>& heights){
        int n=heights.size();
        stack<int> s;
        vector<int> pse(n);
        pse[0]=-1;
        s.push(0);
        for(int i=1;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                pse[i]=s.top();
            }
            else
            {
                pse[i]=-1;
            }
            s.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse=nextSmaller(heights);
        vector<int> pse=prevSmaller(heights);
        int ans=0;
        for(int i=0;i<heights.size();i++){
            int l,r;
            l=pse[i]+1;
            r=nse[i]-1;
            ans=max(ans,(r-l+1)*heights[i]);
            
        }
        return ans;
    }
};
