/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q,p;
        q.push(cloned);
        p.push(original);
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto x=q.front();
                q.pop();
                auto y=p.front();
                p.pop();
                if(y==target)return x;
                
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                
                if(y->left)p.push(y->left);
                if(y->right)p.push(y->right);
            }
        }
        return NULL;
    }
};