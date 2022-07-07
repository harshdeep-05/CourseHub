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
    
    void solve(TreeNode* root,int cur,int &ans)
    {
        if(root)
        {
            cur=cur*2+root->val;
            if(!root->left && !root->right)
                ans+=cur;
        }
        if(root->left)solve(root->left,cur,ans);
        if(root->right)solve(root->right,cur,ans);
        
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};