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
    int solve(TreeNode* root,long long sum)
    {
        if(!root)return 0;
        
        int count=0;
        if(sum==(long long)root->val)count++;
        return count+solve(root->left,sum-root->val)+
                     solve(root->right,sum-root->val);
        
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        return solve(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};