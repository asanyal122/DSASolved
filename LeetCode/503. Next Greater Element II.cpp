class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        stack<int> s;
        
        for(int i=n-2;i>=0;i--)
        {
            s.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i]=s.top();
            }
            else
            {
                ans[i]=-1;
            }
            s.push(nums[i]);
        }
        
        
        return ans;
        
    }
};
