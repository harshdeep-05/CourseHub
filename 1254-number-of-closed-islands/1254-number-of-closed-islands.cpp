class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size(),n=grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=0)return ;
        
        grid[i][j]=-1;
        
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 && (i*j==0 || i==m-1 || j==n-1))
                {
                    dfs(grid,i,j);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};