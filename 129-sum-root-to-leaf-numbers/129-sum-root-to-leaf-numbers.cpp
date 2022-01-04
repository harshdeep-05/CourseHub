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
    void solve(TreeNode* root,int n,int &ans)
    {
        if(root->left)solve(root->left,n*10+root->val,ans);
        if(root->right)solve(root->right,n*10+root->val,ans);
        
        if(!root->left && !root->right)
        {
            ans+=n*10+root->val;
            
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        int n=root->val;
        solve(root,0,ans);
        return ans;
            
        
    }
};