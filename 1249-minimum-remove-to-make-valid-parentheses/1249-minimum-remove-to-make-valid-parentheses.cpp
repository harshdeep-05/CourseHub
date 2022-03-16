class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')open--;
            if(s[i]=='(')open++;
            
            if(open<0 && s[i]==')'){
                s.erase(i,1);
                i--;
                open++;
            }
        }
        if(open==0)return s;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(open && s[i]=='(')
            {
                s.erase(i,1);
                open--;
            }
        }
        return s;
    }
};