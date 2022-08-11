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
    void solve(TreeNode* root,unordered_map<int,vector<int>> &m)
    {
        int par=root->val;
        if(m.find(par)==m.end())return ;
        vector<int> v=m[par];
        
        if(v[0])root->left=new TreeNode(v[0]);
        // else root->left=NULL;
        if(v[1])root->right=new TreeNode(v[1]);
        // else root->right=NULL;
        
        // if(!root->left && !root->right)return;
        
        if(root->left)solve(root->left,m);
        if(root->right)solve(root->right,m);
        return ;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<int>> m;
        unordered_map<int,int> incoming;
        
        for(auto v:descriptions)
        {
            int par=v[0];
            if(m.find(par)==m.end())
            {
                vector<int> v(2,0);
                m[par]=v;
            }
            m[par][1-v[2]]=v[1];
            incoming[v[1]]++;
        }
        int root_val;
        for(auto i:m)
        {
            if(incoming.find(i.first)==incoming.end())
            {
                root_val=i.first;
                break;
            }
        }
        TreeNode* root=new TreeNode(root_val),*temp=root;
        solve(temp,m);
        return root;
        
        
        
    }
};