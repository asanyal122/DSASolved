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
    int maxDepth(TreeNode* root) {
        //if node is null then return 0
        if(root==nullptr)
        {
            return 0;
        }
        
        //if current node is leaf return 1
        if(root->left==nullptr && root->right==nullptr)
        {
            return 1;
        }
        
        //Otherwise recur and get the maxDepth for left and right subtree
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
