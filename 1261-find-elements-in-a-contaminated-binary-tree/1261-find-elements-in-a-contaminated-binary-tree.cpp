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
class FindElements {
    TreeNode* head;
    unordered_map<int,int> m;
public:
    void solve(TreeNode* head)
    {
        if(!head)return;
        int x=head->val;
        
        if(head->left){
            head->left->val=2*x+1;
            m[2*x+1]=1;
            solve(head->left);
        }
        
        if(head->right){
            head->right->val=2*x+2;
            m[2*x+2]=1;
            solve(head->right);
        }
        
    }
    FindElements(TreeNode* root) {
        head=root;
        if(head)head->val=0;
        m[0]=1;
        solve(head);
    }
    
    bool find(int target) {
        return (m.find(target)!=m.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */