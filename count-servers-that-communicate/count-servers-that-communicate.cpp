class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid[0].size(),m=grid.size();
        vector<int> rows(m,0),col(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] && (rows[i]>1 || col[j]>1))ans++;
            }
        }
        
        
        return ans;
    }
};