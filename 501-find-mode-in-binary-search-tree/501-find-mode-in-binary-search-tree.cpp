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
    vector<int> findMode(TreeNode* root) {
        map<int,int> m;
        queue<TreeNode*> q;
        q.push(root);
        int mode=0;
        while(!q.empty())
        {
            auto top=q.front();
            m[top->val]++;
            mode=max(mode,m[top->val]);
            q.pop();
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
        }
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second==mode)ans.push_back(i.first);
        }
            
        
        return ans;
        
    }
};