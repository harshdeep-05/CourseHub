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
        vector<int> p;
        while(temp)
        {
            p.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        sort(p.begin(),p.end());
        int i=0;
        while(i<p.size())
        {
            temp->val=p[i++];
            temp=temp->next;
        }
        return head;
    }
};