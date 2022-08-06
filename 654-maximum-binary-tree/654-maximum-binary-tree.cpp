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
    TreeNode* solve(vector<int>& nums,int low,int high)
    {
        if(high==low)return NULL;
        
        int mx=0,mx_idx=0;
        for(int i=low;i<high;i++)
        {
            mx=max(nums[i],mx);
            if(nums[i]==mx)mx_idx=i;
        }
        TreeNode* root=new TreeNode(mx);
        root->left=solve(nums,low,mx_idx);
        root->right=solve(nums,mx_idx+1,high);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int mx=0,idx=0;
        for(int i=0;i<nums.size();i++)
        {
            mx=max(nums[i],mx);
            if(nums[i]==mx)idx=i;
        }
        
        return solve(nums,0,nums.size());
    }
};