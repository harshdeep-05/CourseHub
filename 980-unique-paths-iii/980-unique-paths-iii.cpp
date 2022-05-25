class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int steps,int empty_cells)
    {
        int m=grid.size(),n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1)return 0;
        if(grid[i][j]==2 )return steps==empty_cells?1:0;
        
        grid[i][j]=-1;
        int path=solve(grid,i+1,j,steps+1,empty_cells)+
                solve(grid,i-1,j,steps+1,empty_cells)+
                solve(grid,i,j-1,steps+1,empty_cells)+
                solve(grid,i,j+1,steps+1,empty_cells);
        grid[i][j]=0;
        
        return path;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_i,start_j;
        int empty_cells=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    start_i=i;
                    start_j=j;
                }
                if(grid[i][j]!=-1)empty_cells++;
            }
        }
        
        return solve(grid,start_i,start_j,1,empty_cells);
    }
};