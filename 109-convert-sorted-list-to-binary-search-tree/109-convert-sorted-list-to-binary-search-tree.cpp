/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(ListNode* head)
    {
        if(!head)return NULL;
        if(!head->next)
            return new TreeNode(head->val);
        
        auto slow=head,fast=head;
        auto premid=head;
        while(fast && fast->next)
        {
            premid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        premid->next=NULL;
        TreeNode* node=new TreeNode(slow->val);
        
        node->left=solve(head);
        node->right=solve(slow->next);
        
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        return solve(head);
    }
};