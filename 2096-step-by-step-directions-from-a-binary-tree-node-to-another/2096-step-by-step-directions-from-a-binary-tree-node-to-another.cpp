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
    TreeNode* solve(TreeNode* root, int s, int t)
    {
        if(!root || root->val==s || root->val==t)
            return root;
        
        auto left=solve(root->left,s,t);
        auto right=solve(root->right,s,t);
        
        if(!left)return right;
        if(!right)return left;
        
        return root;
    }
    int lca_start(TreeNode* root,int start,int cnt)
    {
        if(!root)return 0;
        if(root->val==start)return cnt;
        
        int left=lca_start(root->left,start,cnt+1);
        int right=lca_start(root->right,start,cnt+1);
        return max(left,right);
    }
    bool lca_end(TreeNode* root,int end,string &s)
    {
        if(!root)return 0;
        if(root->val==end)return 1;
        
        bool left=lca_end(root->left,end,s);
        bool right=lca_end(root->right,end,s);
        
        if(left)s+='L';
        if(right)s+='R';
        
        return left or right;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca=solve(root,startValue,destValue);
        int up=lca_start(lca,startValue,0);
        string ans="";
        while(up--)ans+='U';
        string down="";
        lca_end(lca,destValue,down);
        reverse(down.begin(),down.end());
        ans+=down;
        return ans;
            
        
    }
};