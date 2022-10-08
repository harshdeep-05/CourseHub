class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid[0].size(),m=grid.size();
        if(n*m==1)return 0;
        queue<vector<int>> q;
        q.push({0,0,k,0});  // x,y,k,steps
        int d[5]={1,0,-1,0,1};
        int vis[m][n];
        memset(vis,-1,sizeof vis);
        vis[0][0]=k;
        while(!q.empty())
        {
            auto v=q.front();
            q.pop();
            int i=v[0],j=v[1],coins=v[2],steps=v[3];
            if(i==m-1 && j==n-1)
            {
                return steps;
            }
            if(grid[i][j]==1)
            {
                if(coins)coins--;
                else continue;
            }
            for(int r=0;r<4;r++)
            {
                int x=i+d[r],y=j+d[r+1];
                if(x<0 || x>=m || y<0 || y>=n || vis[x][y]>=coins)continue;
                vis[x][y]=coins;
                q.push({x,y,coins,steps+1});
            }
        }
        return -1;
    }
};