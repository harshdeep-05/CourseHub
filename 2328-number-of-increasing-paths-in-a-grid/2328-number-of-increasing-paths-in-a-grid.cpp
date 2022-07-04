class Solution {
public:
    int d[5]={1,0,-1,0,1};
    const int mod=1e9+7;
    int dp[1001][1001];
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size(),n=grid[0].size();
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1;
        for(int r=0;r<4;r++)
        {
            int x=i+d[r],y=j+d[r+1];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]>grid[i][j])
                ans=(ans+dfs(grid,x,y)%mod)%mod;
        }
        return dp[i][j]=ans;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                ans=(ans+dfs(grid,i,j)%mod)%mod;
            }
        }
        return ans;
    }
};