class Solution {
public:
    int dp[101][101];
    bool valid(int i,int j,int m,int n)
    {
        return (i>=0 && i<m && j>=0 && j<n);
    }
    int solve(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size(),n=grid[0].size();
        if(!valid(i,j,m,n) || grid[i][j]==1)return 0;
        if(i==m-1 && j==n-1)return 1;
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(grid,i+1,j)+solve(grid,i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        memset(dp,-1,sizeof dp);
        return solve(obstacleGrid,0,0);
    }
};