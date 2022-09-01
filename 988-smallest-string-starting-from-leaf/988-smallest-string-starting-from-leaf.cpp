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
    string ans="";
    void solve(TreeNode* root,string cur)
    {
        if(!root)
            return;
        
        cur+=root->val+'a';
        if(!root->left && !root->right)
        {
            string s=cur;
            reverse(s.begin(),s.end());
            if(ans.empty())ans=s;
            else
            {
                ans=min(ans,s);
            }
            return ;
        }
        
        solve(root->left,cur);
        solve(root->right,cur);
        cur.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string cur="";
        solve(root,cur);
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};