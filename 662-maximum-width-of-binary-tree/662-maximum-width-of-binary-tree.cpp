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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if (!root) return 0;
        queue<pair<TreeNode*,unsigned long long int>> q;
        q.push({root,1});
        
        while(!q.empty())
        {
            unsigned long long int n=q.size(),l=q.front().second,r=l;
            while(n--)
            {
                TreeNode* x=q.front().first;
                r=q.front().second;
                q.pop();
                if(x->left)q.push({x->left,r*2});
                if(x->right)q.push({x->right,r*2+1});
            }
            ans=max(ans,int(r-l+1));
        }
        return ans;
    }
};