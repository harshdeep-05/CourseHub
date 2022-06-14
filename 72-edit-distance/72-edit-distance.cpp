class Solution {
public:
    int dp[501][501];
    int solve(string a,string b,int n,int m)
    {
        if(m==0)return n;
        if(n==0)return m;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1])return dp[n][m]=solve(a,b,n-1,m-1);
        return dp[n][m]=min({solve(a,b,n-1,m),solve(a,b,n-1,m-1),solve(a,b,n,m-1)})+1;
    }
    int minDistance(string a, string b) {
        memset(dp,-1,sizeof dp);
        return solve(a,b,a.size(),b.size());
    }
};