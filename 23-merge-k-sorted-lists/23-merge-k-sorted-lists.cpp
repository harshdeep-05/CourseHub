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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> q;
        for(auto i:lists)
        {
            ListNode *temp=i;
            while(temp){
                q.push(temp->val);
                temp=temp->next;
            }
            
        }
        ListNode* head=NULL,*temp;
        while(!q.empty())
        {
            temp=new ListNode(q.top());
            temp->next=head;
            head=temp;
            q.pop();
        }
        return head;
    }
};