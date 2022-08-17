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
    int deep(TreeNode* root)
    {
        if(!root)return 0;
        
        return max(deep(root->left),deep(root->right))+1;
    }
    TreeNode* lca(TreeNode* root,int &depth,int h)
    {
        if(!root || depth==h)
            return root;
        
        auto l=lca(root->left,depth,h+1);
        auto r=lca(root->right,depth,h+1);
        
        if(l&&r)return root;
        if(l)return l;
        return r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth=deep(root);
        // cout<<depth;
        return lca(root,depth,1);
    }
};