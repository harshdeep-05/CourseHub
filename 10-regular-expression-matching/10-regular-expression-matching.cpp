class Solution {
public:
    int dp[21][31];
    bool solve(string s,string p,int n,int m)
    {
        if(n<0 && m<0)return 1;
        if(m<0)return 0;
        if(n<0)
        {
            if(p[m]=='*')
                return solve(s,p,n,m-2);
            return 0;
        }
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(s[n]==p[m] || p[m]=='.')
            return dp[n][m]=solve(s,p,n-1,m-1);
        
        if(p[m]=='*')
        {
            if(s[n]==p[m-1] || p[m-1]=='.')
                return dp[n][m]=solve(s,p,n-1,m)||solve(s,p,n,m-2);
            else
                return dp[n][m]=solve(s,p,n,m-2);
        }
        return dp[n][m]=0;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof dp);
        int n=s.size(),m=p.size();
        return solve(s,p,n-1,m-1);
    }
};