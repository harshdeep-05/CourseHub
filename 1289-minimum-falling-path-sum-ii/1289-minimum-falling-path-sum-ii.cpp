class Solution {
public:
    int dp[201][202];
    int solve(vector<vector<int>>& grid,int row,int prev_col)
    {
        if(row==grid.size())return 0;
        if(dp[row][prev_col]!=-1)return dp[row][prev_col];
        int cur=INT_MAX;
        for(int j=0;j<grid.size();j++)
        {
            if(j==prev_col)continue;
            cur=min(solve(grid,row+1,j)+grid[row][j],cur);
        }
        return dp[row][prev_col]=cur;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return solve(grid,0,201);
    }
};