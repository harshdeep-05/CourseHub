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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        if(!root)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        par[root]=NULL;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto node=q.front();
                q.pop();
                //if(i==k)ans.push_back(node->val);
                if(node->left){
                    par[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    par[node->right]=node;
                    q.push(node->right);
                }
                
            }//i++;
        }
        q.push(target);
        unordered_map<TreeNode*, bool> vis;
        vis[target]=true;
        int i=0;
        while(!q.empty())
        {
            int n=q.size();
            if(i==k)break;
            while(n--)
            {
                auto node=q.front();
                q.pop();
                //if(i==k)ans.push_back(node->val);
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(par[node] && !vis[par[node]])
                {
                    q.push(par[node]);
                    vis[par[node]]=true;
                }
                
            }i++;
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};