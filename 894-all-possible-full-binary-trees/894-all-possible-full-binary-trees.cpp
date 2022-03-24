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
    unordered_map<int,vector<TreeNode*> > m;
    vector<TreeNode*> allPossibleFBT(int n) {
        
        vector<TreeNode*> ans;
        if(n==0 || n%2==0)return {};
        if(m.find(n)!=m.end())return m[n];
        if(n==1)
        {
            TreeNode* root=new TreeNode(0);
            m[1]={root};
            return {root};
        }
        
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(n-i-1);
            
            for(int l=0;l<left.size();l++)
            {
                for(int r=0;r<right.size();r++)
                {
                    TreeNode* root= new TreeNode(0);
                    root->left=left[l];
                    root->right=right[r];
                    ans.push_back(root);
                }
                
            }
            
        }
        m[n]=ans;
        return ans;
    }
};