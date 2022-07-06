/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root,vector<int> &ans)
    {
        if(!root)return;
        
        for(auto node:root->children)
        {
            solve(node,ans);
        }
        ans.push_back(root->val);
        return;
    }
        
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(!root)return ans;
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            int n=s.size();
            while(n--)
            {
                auto node=s.top();
                s.pop();
                ans.push_back(node->val);
                for(auto v:node->children)
                {
                    s.push(v);
                }
                
            }
        }
        //solve(root,ans);
        reverse(begin(ans),end(ans));
        return ans;
    }
};