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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)return 0;
        int mn=INT_MAX,ans=INT_MAX,flag=1;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int n=q.size();
            while(n--)
            {
                auto x=q.front();
                q.pop();
                mn=min(mn,x->val);
                if(x->val!=mn){
                    ans=min(ans,x->val);
                    flag=0;
                }
                
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
            
        }
        if(ans==INT_MAX && flag)return -1;
        else return ans;
    }
};