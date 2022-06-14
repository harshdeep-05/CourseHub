class Solution {
public:
    int dp[501][501];
    int solve(string a,string b,int n,int m)
    {
        if(n==0 || m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(a[n-1]==b[m-1])return dp[n][m]=solve(a,b,n-1,m-1)+1;
        return dp[n][m]=max(solve(a,b,n-1,m),solve(a,b,n,m-1));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        int n=word1.size(),m=word2.size();
        int l=solve(word1,word2,n,m);
        return n-l + m-l;
    }
};