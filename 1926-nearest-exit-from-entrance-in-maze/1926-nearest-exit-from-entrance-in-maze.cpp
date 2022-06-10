class Solution {
public:
    int d[5]={1,0,-1,0,1};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& E) {
        int m=maze.size(),n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({E[0],E[1]});
        maze[E[0]][E[1]]='+';
        
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            ans++;
            while(s--)
            {
                auto [i,j]=q.front();
                q.pop();
                for(int r=0;r<4;r++)
                {
                    int x=i+d[r],y=j+d[r+1];
                    if(x<0 || y<0 || x>=m || y>=n|| maze[x][y]=='+')
                        continue;
                    
                    if(x==0 || y==0 || x==m-1 || y==n-1)return ans;
                    
                    q.push({x,y});
                    maze[x][y]='+';
                    
                }
            }
        }
        return -1;
    }
};