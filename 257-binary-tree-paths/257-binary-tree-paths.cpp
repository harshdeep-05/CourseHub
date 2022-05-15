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
    vector<string> ans;
    void dfs(TreeNode* root,string cur)
    {
        if(!root->left && !root->right){
            ans.push_back(cur);
            return;
        }
        if(root->left)
            dfs(root->left,cur+"->"+to_string(root->left->val));
        if(root->right)
            dfs(root->right,cur+"->"+to_string(root->right->val));
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string cur=to_string(root->val);
        if(!root)return ans;
        dfs(root,cur);
        return ans;
    }
};