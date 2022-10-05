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
    
    void solve(TreeNode* node,int val,int depth)
    {
        if(!node)
            return;
        
        if(depth==1)
        {
            auto temp=node->left;
            node->left=new TreeNode(val);
            node->left->left=temp;
            
            temp=node->right;
            node->right=new TreeNode(val);
            node->right->right=temp;
        }
        else 
        {
            solve(node->left,val,depth-1);
            solve(node->right,val,depth-1);
        }
        return;
    }
    
//     void solve(TreeNode* cur,TreeNode* par,int val,int depth,int left)
//     {
//         if(!cur)return;
        
//         if(depth==2)
//         {
//             if(left)
//             {
//                 auto node=new TreeNode(val);
//                 par->left=node;
//                 node->left=cur;
//             }
//             else
//             {
//                 auto node=new TreeNode(val);
//                 par->right=node;
//                 node->right=cur;
//             }
//             return;
//         }
        
// //         if(cur && depth==2 && cur->left==NULL && cur->right==NULL)
// //         {
// //             auto node=new TreeNode(val);
// //             cur->left=node;
// //             cur->right=node;
// //             return;
// //         }
        
        
//         if(cur->left)solve(cur->left,cur,val,depth-1,1);
//         if(cur->right)solve(cur->right,cur,val,depth-1,0);
//         return;
//     }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            auto node=new TreeNode(val);
            node->left=root;
            return node;
        }
        
        // if(root->left)solve(root->left,root,val,depth-1,1);
        // if(root->right)solve(root->right,root,val,depth-1,0);
        solve(root,val,depth-1);
        
        return root;
    }
};