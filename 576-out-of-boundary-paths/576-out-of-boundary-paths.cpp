class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    int d[5]={1,0,-1,0,1};
    int solve(int m, int n, int k, int i, int j)
    {
        if(i==m || j==n || i<0 || j<0)return 1;
        if(k==0)return 0;
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
        int ans=0;
        for(int r=0;r<4;r++)
        {
            ans=(ans+solve(m,n,k-1,i+d[r],j+d[r+1]))%mod;
        }
        return dp[i][j][k]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof dp);
        return solve(m,n,maxMove,startRow,startColumn);
    }
};