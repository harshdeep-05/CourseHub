class Solution {
public:
    bool canBeValid(string s, string locked) {
        int open=0,n=s.size();
        if(n%2) return false;
        for(int i=0;i<n;i++)
        {
            if(locked[i]=='1')
            {
                if(s[i]==')')open--;
                else open++;
                if(open<0)return 0;
            }
            else open++;
        }
        open=0;
        for(int i=n-1;i>=0;i--)
        {
            if(locked[i]=='1')
            {
                if(s[i]=='(')open--;
                else open++;
                if(open<0)return 0;
            }
            else open++;
        }
        return 1;
    }
    
};