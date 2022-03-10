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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        vector<int> v;
        int n=0;
        auto node=head;
        while(node)
        {
            v.push_back(node->val);
            node=node->next;
            n++;
        }
        
        k=k%n;
        if(n*k==0 || n==1 || n==k)return head;
        k=n-k;
        node=head;
        while(node)
        {
            node->val=v[k];
            node=node->next;
            k=(k+1)%n;
        }
        return head;
    }
};