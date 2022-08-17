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
    TreeNode* lca(TreeNode* root,TreeNode* a,TreeNode* b)
    {
        if(!root)
            return NULL;
        
        if(root==a || root==b)return root;
        
        auto l=lca(root->left,a,b);
        auto r=lca(root->right,a,b);
        
        if(l && r)return root;
        
        if(!l)return r;
        return l;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // int last_size=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v;
        while(!q.empty())
        {
            int s=q.size();
            // last_size=s;
            v.clear();
            while(s--)
            {
                auto top=q.front();
                q.pop();
                v.push_back(top);
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        // cout<<v.size()<<" ";
        if(v.size()==1)return v[0];
        TreeNode* a=v[0],*b=v.back();
        
        return lca(root,a,b);
        // return NULL;
    }
};