/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            while(s)
            {
                auto top=q.front();
                //cout<<top->val<<endl;
                q.pop();
                s--;
                if(s==0)top->next=NULL;
                else
                {
                    top->next=q.front();
                }
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
                
        }
        return root;
    }
};