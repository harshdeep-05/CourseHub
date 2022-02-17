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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return head;
        while(head->val==val && head->next)
        {
            head=head->next;
        }
        ListNode* temp=head;
        
        if(temp==NULL)return NULL;
        while(temp && temp->next)
        {
            ListNode* next=temp->next;
            if(next==NULL)break;
            while(next){
                if(next->val==val)
                {
                    if(next->next==NULL)
                    {
                        temp->next=NULL;
                    }
                    next=next->next;
                }
                else break;
            }
            temp->next=next;
            temp=next;
        }
        if(head->val==val)return NULL;
        return head;
    }
};