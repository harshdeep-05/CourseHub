class Solution {
public:
    int dp[101];
    int solve(string s,int i)
    {
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=solve(s,i+1);
        
        if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6')))ans=ans+solve(s,i+2);
        
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return solve(s,0);
    }
};