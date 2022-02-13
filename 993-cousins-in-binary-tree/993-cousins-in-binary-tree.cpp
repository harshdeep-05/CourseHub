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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        int par_x,par_y;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            int yes=0;
            while(s--)
            {
                auto top=q.front();
                q.pop();
                if(top->val==x || top->val==y)yes++;
                
                if(top->right)
                {
                    if(top->right->val==x)par_x=top->val;
                    if(top->right->val==y)par_y=top->val;
                    q.push(top->right);
                }
                if(top->left)
                {
                    if(top->left->val==x)par_x=top->val;
                    if(top->left->val==y)par_y=top->val;
                    q.push(top->left);
                }
            }
            
            if(par_x==par_y || yes==1)return false;
        }
        return true;
    }
};