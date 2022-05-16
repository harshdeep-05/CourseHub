class Solution {
public:
    int x[8]={1,1,0,-1,-1,-1,0,1};
    int y[8]={0,1,1,1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans=0,n=grid.size();
        if(grid[0][0] || grid[n-1][n-1])return -1;
        while(!q.empty())
        {
            ans++;
            int s=q.size();
            while(s--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                if(i==n-1 && j==n-1)return ans;
                
                for(int r=0;r<8;r++)
                {
                    int X=i+x[r],Y=j+y[r];
                    if(X>=n || Y>=n || X<0 || Y<0 || grid[X][Y]==1)continue;
                    
                    grid[X][Y]=1;
                    q.push({X,Y});
                }
            }
            
        }
        return -1;
    }
};