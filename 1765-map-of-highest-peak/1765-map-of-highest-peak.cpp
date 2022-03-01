class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        //vector<vector<int> > v(m,vector<int> (n,-1));
        int d[5]={1,0,-1,0,1};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //isWater[i][j]=1-isWater[i][j];
                if(isWater[i][j]==1)q.push({i,j});
                isWater[i][j]--;
            }
        }
        int mx=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                int x=q.front().first,y=q.front().second;
                q.pop();
                /*
                for(int r=0;r<4;r++)
                {
                    int X=x+d[r],Y=y+d[r];
                    if(X>=0 && X<m && Y>=0 && Y<n && isWater[X][Y]==-1)
                    {
                        isWater[X][Y]=mx+1;
                        q.push({X,Y});
                    }
                }
                */
                
                if(x>0 && isWater[x-1][y]==-1)
                {
                    isWater[x-1][y]=mx+1;
                    q.push({x-1,y});
                }
                if(y>0 && isWater[x][y-1]==-1)
                {
                    isWater[x][y-1]=mx+1;
                    q.push({x,y-1});
                }
                if(x+1<m && isWater[x+1][y]==-1)
                {
                    isWater[x+1][y]=mx+1;
                    q.push({x+1,y});
                }
                if(y+1<n && isWater[x][y+1]==-1)
                {
                    isWater[x][y+1]=mx+1;
                    q.push({x,y+1});
                }
                
            }
            mx++;
        }
        return isWater;
        
    }
};