class Solution {
public:
    int n;
    int solve(vector<vector<int>>& grid,int r,int c)
    {
        int a=0,b=0;
        for(int i=0;i<n;i++)a=max(grid[r][i],a);
        for(int i=0;i<n;i++)b=max(grid[i][c],b);
        return min(a,b);
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        n=grid.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=solve(grid,i,j)-grid[i][j];
            }
        }
        return ans;
    }
};