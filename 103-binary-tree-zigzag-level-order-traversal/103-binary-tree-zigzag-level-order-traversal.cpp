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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode* > q;
        q.push(root);
        
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v;
            while(n--)
            {
                auto node=q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(level%2)
            {
                for(int i=0;i<v.size()/2;i++)
                    swap(v[i],v[v.size()-i-1]);
            }
            ans.push_back(v);
            level++;
        }
            return ans;
    }
};