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
    TreeNode *first,*last,*prev;
    void solve(TreeNode* root)
    {
        if(!root)return;
        
        solve(root->left);
        if(prev!=NULL && root->val<prev->val)
        {
            if(first==NULL)first=prev;
            last=root;
        }
        prev=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=last=prev=NULL;
        solve( root);
        swap(first->val,last->val);
    }
};