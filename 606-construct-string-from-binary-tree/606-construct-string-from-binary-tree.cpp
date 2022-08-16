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
    void solve(TreeNode* root,string &ans)
    {
        if(!root)
        {
            ans+="";
            return;
        }
        ans+='(';
        ans+=to_string(root->val);
        if(root->left)solve(root->left,ans);
        if(root->right)solve(root->right,ans);
        ans+=')';
        return;
    }
    string tree2str(TreeNode* root) {
        // string ans="";
        // // ans+=to_string(root->val);
        // solve(root,ans);
        // return ans;
        
        if(!root)
            return "";
        if(!root->left && !root->right)
        {
            return to_string(root->val)+"";
        }
        if(!root->right)
        {
            return to_string(root->val)+'('+tree2str(root->left)+')';
        }
        
        return to_string(root->val)+
            '('+tree2str(root->left)+")(" +tree2str(root->right)+')';
    }
};