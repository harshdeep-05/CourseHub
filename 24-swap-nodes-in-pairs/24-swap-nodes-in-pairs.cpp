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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* temp=head;
        while(temp && temp->next)
        {
            //ListNode* temp=even->next;
            swap(temp->next->val,temp->val);
            
            temp=temp->next->next;
        }
        return head;
    }
};