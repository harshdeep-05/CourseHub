class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();
        // priority_queue<vector<int>> q;
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        
        int d[5]={1,0,-1,0,1};
        bool vis[m][n];
        memset(vis,0,sizeof vis);
        
        
        for(int i=0;i<m;i++)
        {
            q.push({h[i][0],i,0});
            q.push({h[i][n-1],i,n-1});
            vis[i][0]=1;
            vis[i][n-1]=1;
        }
        for(int i=0;i<n;i++)
        {
            q.push({h[0][i],0,i});
            q.push({h[m-1][i],m-1,i});
            vis[0][i]=1;
            vis[m-1][i]=1;
        }
        
        int ans=0;
        while(!q.empty())
        {
            auto v=q.top();
            q.pop();
            int height=v[0],row=v[1],col=v[2];
            for(int r=0;r<4;r++)
            {
                int x=row+d[r],y=col+d[r+1];
                if(x<0 || x>=m || y<0 || y>=n || vis[x][y])continue;
                
                vis[x][y]=1;
                ans+=max(0,height-h[x][y]);
                q.push({max(height,h[x][y]),x,y});
            }
        }
        
        return ans;
    }
};