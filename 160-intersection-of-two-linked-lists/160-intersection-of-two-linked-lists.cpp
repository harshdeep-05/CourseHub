/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> m;
        while(headA)
        {   
            m[headA]++;
            headA=headA->next;
        }
        while(headB)
        {   
            m[headB]++;
            headB=headB->next;
        }   
        
        for(auto i:m)
        {
            if(i.second==2)return i.first;
        }
        
        return NULL;
    }
};