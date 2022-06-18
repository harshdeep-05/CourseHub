/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)return 0;
        int l=solve(root->left,p,q);
        int r=solve(root->right,p,q);
        
        int m=(root==p || root==q);
        if(l+r+m>=2)ans=root;
        
        return (l+r+m>0);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};