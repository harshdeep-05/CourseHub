class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c)
    {
        int m=grid.size(),n=grid[0].size();
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0)return 0;
        grid[r][c]=0;
        
        return(1+dfs(grid,r+1,c)+dfs(grid,r,c+1)+
                 dfs(grid,r-1,c)+dfs(grid,r,c-1));
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] && (i*j==0|| i==m-1 || j==n-1))
                    dfs(grid,i,j);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] && i*j>0 && i!=m-1 && j!=n-1)
                    ans+=dfs(grid,i,j);
            }
        }
        return ans;
    }
};