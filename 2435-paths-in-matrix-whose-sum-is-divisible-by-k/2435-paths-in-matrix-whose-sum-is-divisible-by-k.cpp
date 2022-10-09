class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>> dp;
    int x,m,n;
    int solve(vector<vector<int>>& v,int i,int j,int rem)
    {
        rem=(rem+v[i][j])%x;
        if(i==m-1 && j==n-1)
        {
            return (rem==0);
        }
        // if(dp[i][j][rem]!=-1)
        // {
        //     return dp[i][j][rem];
        // }
        if(dp[i*n+j][rem]!=-1)return dp[i*n+j][rem];
        int ans=0;
        if(i+1<m)ans+=solve(v,i+1,j,rem);
        if(j+1<n)ans+=solve(v,i,j+1,rem);
        return dp[i*n+j][rem]=ans%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size(),n=grid[0].size();
        x=k;
        // dp=vector<vector<vector<int>>> (m,vector<vector<int>>(n,vector<int> (k,-1)));
        dp=vector<vector<int>> (m*n,vector<int> (k,-1));
        return solve(grid,0,0,0);
    }
};