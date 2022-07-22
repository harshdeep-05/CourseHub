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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* temp=head;
        while(temp)
        {
            int x=temp->val;
            ListNode* temp2=temp;
            while(temp2 && temp2->val<=x)
            {
                temp2=temp2->next;
            }
            if(temp2==NULL)ans.push_back(0);
            else ans.push_back(temp2->val);
            temp=temp->next;
        }
        return ans;
    }
};