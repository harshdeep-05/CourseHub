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
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        priority_queue<int> p;
        while(temp)
        {
            p.push(-temp->val);
            temp=temp->next;
        }
        temp=head;
        while(p.size())
        {
            temp->val=-p.top();
            p.pop();
            temp=temp->next;
        }
        return head;
    }
};