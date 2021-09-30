/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void minDepthHelper(TreeNode* root,int tillNode,int &ans)
    {
        //if we are in leaf
        if(root->left==nullptr && root->right==nullptr)
        {
            ans=min(ans,tillNode+1);
            return;
        }
        if(root->left != nullptr)
        {
            minDepthHelper(root->left,tillNode+1,ans);
        }
        if(root->right!=nullptr)
        {
            minDepthHelper(root->right,tillNode+1,ans);
        }
    }
    
    int minDepth(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
        int ans=INT_MAX;
        minDepthHelper(root,0,ans);
        return ans;
    }
};
