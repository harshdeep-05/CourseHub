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
        stack<pair<int,int>> s;
        int index=0;
        while(head)
        {
            while(!s.empty() && head->val>s.top().first)
            {
                ans[s.top().second]=head->val;
                s.pop();
            }
            ans.push_back(0);
            s.push({head->val,index});
            head=head->next;
            index++;
        }
        return ans;
        
    }
};