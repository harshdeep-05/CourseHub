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
    vector<int> solve(TreeNode* root)
    {
        if(!root)return {0,0,99999};
        
        vector<int> l=solve(root->left);
        vector<int> r=solve(root->right);
        
        int min_l=min(l[1],l[2]);
        int min_r=min(r[1],r[2]);
        
        int x=l[1]+r[1];
        int y=min(l[2]+min_r,r[2]+min_l);
        int z=1+min(l[0],min_l)+min(r[0],min_r);
        
        return {x,y,z};
        
    }
    int minCameraCover(TreeNode* root) {
        vector<int> ans=solve(root);
        return min(ans[1],ans[2]);
    }
};