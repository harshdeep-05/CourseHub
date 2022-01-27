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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        queue<TreeNode*> q;
        if(root1){
        q.push(root1);
        while(q.size())
        {
            int n=q.size();
            while(n--)
            {
                auto top=q.front();
                q.pop();
                v.push_back(top->val);
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        }
        if(root2){
        q.push(root2);
        while(q.size())
        {
            int n=q.size();
            while(n--)
            {
                auto top=q.front();
                q.pop();
                v.push_back(top->val);
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        }
        sort(v.begin(),v.end());
        return v;
    }
};