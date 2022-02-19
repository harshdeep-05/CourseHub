class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int& r, int& c)
    {
        int m=land.size(),n=land[0].size();
        land[i][j] = 0;
        
        r = max(i, r);
        c = max(j, c);
        
        if(i+1 < m && land[i+1][j] == 1)dfs(land, i+1, j, r, c);
    
        if(j+1 < n && land[i][j+1] == 1)dfs(land, i, j+1, r, c);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m=land.size(),n=land[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(land[i][j]==1)
                {
                    int r=-1,c=-1;
                    dfs(land,i,j,r,c);
                    ans.push_back({i,j,r,c});
                }
            }
            
        }
        return ans;
    }
};