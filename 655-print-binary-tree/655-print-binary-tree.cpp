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
    int height(TreeNode* root)
    {
        if(!root)return 0;
        return max(height(root->left),height(root->right))+1;
    }
    
    void solve(TreeNode* root,vector<vector<string>> &ans,int l,int r,int row)
    {
        if(!root)return;
        
        int col=l+(r-l)/2;
        ans[row][col]=to_string(root->val);
        
        solve(root->left,ans,l,col,row+1);
        solve(root->right,ans,col+1,r,row+1);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int m=height(root);
        int n=pow(2,m)-1;
        vector<vector<string>> ans(m,vector<string> (n,""));
        
        solve(root,ans,0,n,0);
        return ans;
        
    }
};