struct Node{
    Node* list[26];
    int count=0;
    string word;
    
    Node* get(char c)
    {
        if(!list[c-'a'])
        {
            count++;
            list[c-'a']=new Node();
        }
        return list[c-'a'];
    }
    int collect(Node *node)
    {
        if(!node)return 0;
        if(node->count==0)return node->word.size()+1;
        
        int count=0;
        for(auto n:node->list)count+=collect(n);
        return count;
    }
    void add(Node* trie,string s)
    {
        Node* node=trie;
        for(int i=s.size()-1;i>=0;i--)
            node=node->get(s[i]);
        
        node->word=s;
    }
    
    
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Node* trie=new Node();
        for(auto s:words){
            trie->add(trie,s);
        }
        return trie->collect(trie);
    }
};