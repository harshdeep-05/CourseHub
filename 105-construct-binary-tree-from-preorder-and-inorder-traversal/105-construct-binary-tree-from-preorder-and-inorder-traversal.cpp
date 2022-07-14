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
    unordered_map<int,int> inmap;
    int root_idx=0;
    TreeNode* solve(vector<int>& preorder,int left,int right)
    {
        if(left>right)return NULL;
        
        int root_val=preorder[root_idx++];
        TreeNode* root=new TreeNode(root_val);
        root->left=solve(preorder,left,inmap[root_val]-1);
        root->right=solve(preorder,inmap[root_val]+1,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
        {
            inmap[inorder[i]]=i;
        }
        
        return solve(preorder,0,preorder.size()-1);
        
        
    }
};