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
    unordered_map<int,int> m;
    int mx_cnt=0;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        root->val+=l+r;
        m[root->val]++;
        mx_cnt=max(m[root->val],mx_cnt);
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        solve(root);
        for(auto &i:m)
        {
            // cout<<i.first<<" ";
            if(i.second==mx_cnt)ans.push_back(i.first);
        }
        return ans;
    }
};