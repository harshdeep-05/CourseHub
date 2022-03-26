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
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        m[root]=NULL;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto node=q.front();
                q.pop();
                if(node->left)
                {
                    m[node->left]=node;
                    q.push(node->left);
                }
                if(node->right)
                {
                    m[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        int ans=0;
        for(auto i:m)
        {
            auto child=i.first,par=i.second;
            //cout<<child->val<<"\n";
            if(par!=NULL)
            {
                if(m[par] && m[par]->val%2==0){
                    ans+=child->val;
                    //cout<<child->val<<" "<<m[par]->val<<"\n";
                }
            }
        }
        return ans;
    }
};