class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0,open=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')open++;
            else 
            {
                open--;
                if(s[i-1]=='(')ans+=1<<open;
            }
        }
        return ans;
    }
};