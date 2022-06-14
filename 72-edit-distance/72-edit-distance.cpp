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
        //return solve(a,b,a.size(),b.size());
        
        int n=a.size(),m=b.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i*j==0)dp[i][j]=max(i,j);
                else if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min({dp[i-1][j],
                                  dp[i][j-1],
                                  dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[n][m];
    }
};