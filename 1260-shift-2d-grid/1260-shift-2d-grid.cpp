class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        k%=m*n;
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int x=(i + (j + k) / n) % m,y=(j + k) % n;
                ans[x][y]=grid[i][j];
            }
        }
        return ans;
    }
};