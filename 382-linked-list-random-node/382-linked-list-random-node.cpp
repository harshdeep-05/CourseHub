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
    int n=0;
    ListNode *root;
    Solution(ListNode* head) {
        //int n=0;
        root=head;
        ListNode* temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
    }
    
    int getRandom() {
        int i=rand()%n;
        ListNode *temp=root;
        while(temp && i--)
        {
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */