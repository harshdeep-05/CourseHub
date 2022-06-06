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
        unordered_map<ListNode*,int> m;
        ListNode* temp=headA;
        while(temp)
        {
            m[temp]++;
            temp=temp->next;
        }
        temp=headB;
        while(temp)
        {
            m[temp]++;
            if(m[temp]==2)return temp;
            temp=temp->next;
        }
        return NULL;
    }
};