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
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto x=q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }
        sort(v.begin(),v.end());
        unordered_map<int,int> m;
        int x=0,n=v.size();
        for(int i=n-1;i>=0;i--)
        {
            x+=v[i];
            m[v[i]]=x;
        }
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto x=q.front();
                q.pop();
                x->val=m[x->val];
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
            }
        }
        return root;
        
    }
};