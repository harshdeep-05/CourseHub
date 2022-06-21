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
    vector<TreeNode*> ans;
    unordered_map<int,int> m;
    void dfs(TreeNode* &root)
    {
        if(!root)return;
        
        if(m.find(root->val)!=m.end())
        {
            if(root->left && m.find(root->left->val)==m.end())
            {
                ans.push_back(root->left);
            }
            if(root->right && m.find(root->right->val)==m.end())
            {
                ans.push_back(root->right);
            }
            dfs(root->left);
            dfs(root->right);
            root=NULL;
        }
        else
        {
            dfs(root->left);
            dfs(root->right);
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto i:to_delete)m[i]=1;
        if(m.find(root->val)==m.end())ans.push_back(root);
        dfs(root);
        return ans;
    }
};