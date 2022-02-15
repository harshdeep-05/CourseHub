class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> r(n,0),c(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int mx=0,mc=0;
            for(int j=0;j<n;j++)
            {
                mx=max(grid[i][j],mx);
                mc=max(grid[j][i],mc);
            }
            r[i]=mx;
            c[i]=mc;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=min(r[i],c[j])-grid[i][j];
            }
        }
    
        return ans;
    }
};