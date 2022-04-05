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
    void inorder(TreeNode* root,vector<int> &in)
    {
        if(!root)return;
        
        if(root->left)inorder(root->left,in);
        in.push_back(root->val);
        if(root->right)inorder(root->right,in);
        
    }
    
    TreeNode* solve(vector<int>& in,int i,int j)
    {
        if(i>j)return NULL;
        
        int m=(i+j)/2;
        TreeNode* root=new TreeNode(in[m]);
        
        root->right=solve(in,m+1,j);
        root->left=solve(in,i,m-1);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)return root;
        
        vector<int> in;
        inorder(root,in);
        
        return solve(in,0,in.size()-1);
    }
};