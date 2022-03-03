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
    int maxLevelSum(TreeNode* root) {
        int ans_i=INT_MAX,sum=INT_MIN,level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int cur=0;
            level++;
            while(n--)
            {
                auto x=q.front();
                q.pop();
                cur+=x->val;
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            if(cur>sum)ans_i=level;
            sum=max(sum,cur);
        }
        return ans_i;
            
    }
};