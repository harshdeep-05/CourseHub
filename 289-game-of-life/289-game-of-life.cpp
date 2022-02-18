class Solution {
public:
    int dx[8]={1,1,0,-1,-1,-1,0,1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    void gameOfLife(vector<vector<int>>& board) {
        
        int m=board.size(),n=board[0].size();
        int v[m][n];
        memset(v,0,sizeof v);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int r=0;r<8;r++)
                {
                    int x=i+dx[r],y=j+dy[r];
                    if(x>=0 && x<m && y>=0 && y<n){
                       v[i][j]+=board[x][y];
                    }
                }
                cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j])
                {
                    if(v[i][j]<2 || v[i][j]>3)board[i][j]=0;
                }
                else 
                {
                    if(v[i][j]==3)board[i][j]=1;
                }
                    
            }
        }
    }
};