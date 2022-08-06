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
    bool isUnivalTree(TreeNode* root) {
        if(!root)return 1;
        int val=root->val;
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto node=q.top();
                cout<<node<<" ";
                q.pop();
                if(node->val!=val)return 0;
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return true;
    }
};