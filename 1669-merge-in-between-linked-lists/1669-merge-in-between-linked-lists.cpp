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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* i=list1,*j=list2;
        
        for(int x=1;x<a;x++)
        {
            i=i->next;
        }
        ListNode* temp1=i;
        for(int x=a;x<=b;x++)
        {
            temp1=temp1->next;
        }
        i->next=j;
        cout<<temp1->val;
        while(j->next)
        {
            j=j->next;
        }
        j->next=temp1->next;
        temp1->next=NULL;
        return list1;
    }
};