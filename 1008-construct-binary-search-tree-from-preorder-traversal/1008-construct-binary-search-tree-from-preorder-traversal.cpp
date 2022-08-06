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
    TreeNode* solve(vector<int>& v,int l,int r)
    {
        if(l==r)return NULL;
        
        int idx=l+1;
        while(idx<r && v[idx]<v[l])idx++;
        
        TreeNode* root=new TreeNode(v[l]);
        root->left=solve(v,l+1,idx);
        root->right=solve(v,idx,r);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size());
    }
};