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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        //unordered_map<ListNode*,int> m;
        int i=0;
        while(temp)
        {
            //if(m.find(temp)!=m.end())return temp;
            //m[temp]=i++;
            if(temp->val==INT_MAX)return temp;
            temp->val=INT_MAX;
            temp=temp->next;
        }
        return NULL;
    }
};