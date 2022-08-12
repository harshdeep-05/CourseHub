class Solution {
public:
    int dp[101][101][202];
    bool solve(vector<vector<char>>& grid,int i,int j,int open)
    {
        int m=grid.size(),n=grid[0].size();
        if(i>=m || j>=n)
            return 0;
        if(grid[i][j]=='(')open++;
        else open--;
        if(open<0)return 0;
        
        if(dp[i][j][open]!=-1)return dp[i][j][open];
        
        if(i==m-1 && j==n-1)
        {
            return open==0;
        }
        
        bool val=solve(grid,i+1,j,open)||solve(grid,i,j+1,open);
        dp[i][j][open]=val;
        return val;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof dp);
        return solve(grid,0,0,0);
    }
};