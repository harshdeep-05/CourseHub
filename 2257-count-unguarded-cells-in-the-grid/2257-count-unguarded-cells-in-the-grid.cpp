class Solution {
public:
    void dfs(vector<vector<int>> &v,int i,int j)
    {
        int m=v.size(),n=v[0].size();
        if(i<0 || i>=m || j<0 || j>=n || v[i][j]==-1)return;
        
        v[i][j]=2;
        dfs(v,i+1,j);
        dfs(v,i-1,j);
        dfs(v,i,j-1);
        dfs(v,i,j+1);
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m,vector<int> (n,0));
        for(auto w:walls)
        {
            v[w[0]][w[1]]=-1;
            
        }
        for(auto g:guards)
        {
            v[g[0]][g[1]]=1;
        }
        
        for(auto g:guards)
        {
            int x=g[0],y=g[1];
            for(int r=x+1;r<m;r++)
            {
                if(v[r][y]==1 || v[r][y]==-1)break;
                v[r][y]=2;
            }
            for(int r=x-1;r>=0;r--)
            {
                if(v[r][y]==1 || v[r][y]==-1)break;
                v[r][y]=2;
            }
            for(int c=y+1;c<n;c++)
            {
                if(v[x][c]==1 || v[x][c]==-1)break;
                v[x][c]=2;
            }
            for(int c=y-1;c>=0;c--)
            {
                if(v[x][c]==1 || v[x][c]==-1)break;
                v[x][c]=2;
            }
        }
        int ans=0;
        for(auto i:v)
        {
            for(auto j:i)if(j==0)ans++;
        }
        return ans;
    }
};