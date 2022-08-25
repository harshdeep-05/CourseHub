class Solution {
public:
    bool ispalindrome(string &s)
    {
        for(int i=0;i<s.length()/2;i++)
            if(s[i]!=s[s.length()-1-i])
                return 0;
        return 1;
    }
    int cal(string s, int st, vector<int> &dp)
    {
        if(st>=s.length())
            return 0;
        
        if(dp[st]!=-1)
            return dp[st];
        
        string p;
        
        int ans=INT_MAX;
        
        for(int i=st;i<s.length();i++)
        {
            p.push_back(s[i]);
            if(ispalindrome(p))
                ans=min(ans,1+cal(s,i+1,dp));
        }
        
        return dp[st] = ans;
    }
    int minCut(string s) {
        vector<int> dp(s.length(),-1);
        return cal(s,0,dp)-1;
    }
};