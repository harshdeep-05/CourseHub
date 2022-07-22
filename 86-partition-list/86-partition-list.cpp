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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        vector<int> before,after;
        while(temp)
        {
            if(temp->val<x)before.push_back(temp->val);
            else after.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(i<before.size())
        {
            temp->val=before[i++];
            temp=temp->next;
        }
        i=0;
        while(temp)
        {
            temp->val=after[i++];
            temp=temp->next;
        }
        return head;
    }
};