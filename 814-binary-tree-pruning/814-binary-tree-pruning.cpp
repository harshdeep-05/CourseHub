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
    int solve(TreeNode* root,int sum)
    {
        if(!root)
            return 0;
        
        int l=solve(root->left,sum);
        int r=solve(root->right,sum);
        
        if(l==0)
        {
            root->left=NULL;
        }
        if(r==0)
        {
            root->right=NULL;
        }
        return l+r+root->val;
    }
    TreeNode* pruneTree(TreeNode* root) {
        // solve(root,0);
        // if(root->val==0 && !root->left && !root->right)return NULL;
        // return root;
        if(!root)
            return root;
        
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        
        if(root->val==0 && !root->left && !root->right)
            root=NULL;
        
        return root;
    }
};