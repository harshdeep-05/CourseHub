class Solution {
public:
    int dp[1001][1001];
    int solve(string &a,string &b,int m,int n)
    {
        if(m==0 || n==0)
            return 0;
        if(dp[m][n]!=-1)return dp[m][n];
        if(a[m-1]==b[n-1])
        {
            return dp[m][n]=solve(a,b,m-1,n-1)+1;
        }
        return dp[m][n]=max(solve(a,b,m-1,n),solve(a,b,m,n-1));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string a=s;
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof dp);
        return solve(s,a,n,n);
        // return dp[n][n];
        
    }
};