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
    bool solve(TreeNode* root,TreeNode* mi,TreeNode* mx)
    {
        if(!root)return 1;
        
        if((mi && root->val <= mi->val) || (mx && root->val >= mx->val))
            return 0;
        
        return (solve(root->left,mi,root) && solve(root->right,root,mx));
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};