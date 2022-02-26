class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        int board[8][8];
        memset(board,0,sizeof board);
        for(auto v:queens)
        {
            int r=v[0],c=v[1];
            board[r][c]=1;
        }
        int r=king[0],c=king[1];
        int x=-1,y=-1;
        for(int i=0;i<r;i++)if(board[i][c]==1)x=max(x,i);
        if(x!=-1)ans.push_back({x,c});
        x=8;
        for(int i=r+1;i<8;i++)if(board[i][c]==1)x=min(x,i);
        if(x!=8)ans.push_back({x,c});
        
        for(int i=0;i<c;i++)if(board[r][i]==1)y=max(y,i);
        if(y!=-1)ans.push_back({r,y});
        y=8;
        for(int i=c+1;i<8;i++)if(board[r][i]==1)y=min(y,i);
        if(y!=8)ans.push_back({r,y});
        
        int i=0;
        while(r-i>=0 && c-i>=0)
        {
            if(board[r-i][c-i]==1)
            {
                ans.push_back({r-i,c-i});
                break;
            }i++;
        }
        i=0;
        while(r-i>=0 && c+i<8)
        {
            if(board[r-i][c+i]==1)
            {
                ans.push_back({r-i,c+i});
                break;
            }i++;
            
        }
        i=0;
        while(r+i<8 && c+i<8)
        {
            if(board[r+i][c+i]==1)
            {
                ans.push_back({r+i,c+i});
                break;
            }i++;
        }
        i=0;
        while(r+i<8 && c-i>=0)
        {
            if(board[r+i][c-i]==1)
            {
                ans.push_back({r+i,c-i});
                break;
            }
            i++;
        }
        return ans;
    }
};