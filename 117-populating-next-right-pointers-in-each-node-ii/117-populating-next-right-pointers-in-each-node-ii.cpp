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
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            Node *temp=NULL;
            while(n--)
            {
                auto node=q.front();
                q.pop();
                
                node->next=temp;
                temp=node;
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
                if(n==0)temp=NULL;
            }
        }
        return root;
        
    }
};