class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>>& grid,int r,int c1,int c2)
    {
        int n=grid.size(),m=grid[0].size();
        if(r>=n || c1<0 || c1>=m || c2<0 || c2>=m)
            return 0;
        
        
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        
        int cherries=grid[r][c1];
        if(c1!=c2)
            cherries+=grid[r][c2];
        
        int mx=0;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    mx=max(mx,solve(grid,r+1,c1+i,c2+j));
                }
            }
            cherries+=mx;
        
        return dp[r][c1][c2]=cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof dp);
        return solve(grid,0,0,m-1);
    }
};