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
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a)return b;
        if(!b)return a;
        
        if(a->val <= b->val)
        {
            a->next=merge(a->next,b);
            return a;
        }
        else
        {
            b->next=merge(a,b->next);
            return b;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *slow=head, *fast=head->next;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        fast=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(fast));
        
    }
};