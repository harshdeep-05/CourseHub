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
    // map<TreeNode*,int> m;
    map<pair<int,int>,vector<int>> mp;
    void dfs(TreeNode* root,int row,int col)
    {
        if(!root)
            return;
        
        // m[root]=col;
        mp[{row,col}].push_back(root->val);
        if(root->left)dfs(root->left,row+1,col-1);
        if(root->right)dfs(root->right,row+1,col+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        for(auto &i:mp)
        {
            auto v=i.second;
            auto [r,c]=i.first;
            sort(v.begin(),v.end());
            for(auto x:v)
            {
                m[c].push_back(x);
            }
        }
        for(auto &i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
        // map<int,vector<int>> mp;
        
    }
};