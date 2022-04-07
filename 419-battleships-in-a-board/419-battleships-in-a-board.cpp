class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        int m=board.size(),n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n)return;
        if(board[i][j]=='.')return;
        
        board[i][j]='.';
        
        dfs(i+1,j,board);
        dfs(i,j+1,board);
        dfs(i-1,j,board);
        dfs(i,j-1,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='X')
                {
                    dfs(i,j,board);
                    ans++;
                }
            }
        }
        return ans;
    }
};