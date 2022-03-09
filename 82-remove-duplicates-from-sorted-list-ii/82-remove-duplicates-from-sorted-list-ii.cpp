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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* temp=head;
        unordered_map<int,int> m;
        while(temp && temp->next)
        {
            auto next=temp->next;
            if(next->val==temp->val)
            {
                m[next->val]=1;
                while(next && next->val==temp->val)
                {
                    next=next->next;
                }
                temp->next=next;
                temp=next;
            }
            else temp=next;
        }
        while(head && m[head->val]==1 )
        {
            head=head->next;
        }
        ListNode* cur=head,*prev;
        while(cur)
        {
            //cout<<cur->val <<" "<<m[cur->val]<<"\n";
            if(m[cur->val]==1){
                cur=cur->next;
                prev->next=cur;
            }
            else{
                prev=cur;
            cur=cur->next;
            }
        }
        
        return head;
    }
};