class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1)return;
        
        grid[i][j]=2;
        
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    flag=1;
                    break;
                }
            }
            if(flag)break;
        }
        vector<vector<int>> v1,v2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    v1.push_back({i,j});
                }
                else if(grid[i][j]==2)
                {
                    v2.push_back({i,j});
                }
            }
        }
        int ans=n*n;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                ans=min(ans,abs(v1[i][0]-v2[j][0])+abs(v1[i][1]-v2[j][1])-1);
            }
        }
        return ans;
    }
};