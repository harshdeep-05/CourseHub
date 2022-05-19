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
        q.push(original);
        p.push(cloned);
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto a=q.front();
                q.pop();
                auto b=p.front();
                p.pop();
                if(a==target)return b;
                
                if(a->left){
                    q.push(a->left);
                    p.push(b->left);
                }
                if(a->right){
                    q.push(a->right);
                    p.push(b->right);
                }
            }
        }
        return NULL;
    }
};