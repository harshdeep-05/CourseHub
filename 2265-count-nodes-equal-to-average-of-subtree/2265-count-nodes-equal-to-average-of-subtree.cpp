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
    int ans=0;
    vector<int> solve(TreeNode* root)
    {
        if(!root)return {0,0};
        
        auto l=solve(root->left);
        auto r=solve(root->right);
        
        vector<int> v={l[0]+r[0]+root->val,l[1]+r[1]+1};
        if(v[0]/v[1]==root->val)ans++;
        return v;

    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};