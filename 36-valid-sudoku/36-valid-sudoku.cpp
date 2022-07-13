class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            vector<int> v_col(10,0),v_row(10,0);
            
            for(int j=0;j<9;j++)
            {
                char c=board[i][j];
                if(c=='.')continue;
                v_col[c-'0']++;
                if(v_col[c-'0']>1)return 0;
                
            }
        }
        for(int i=0;i<9;i++)
        {
            vector<int> v_row(10,0);
            
            for(int j=0;j<9;j++)
            {
                char c2=board[j][i];
                if(c2=='.')continue;
                v_row[c2-'0']++;
                if(v_row[c2-'0']>1)return 0;
                
            }
        }
        
        for(int row=0;row<9;row+=3)
        {
            for(int col=0;col<9;col+=3)
            {
                vector<int> v(10,0);
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        char c=board[row+i][col+j];
                        if(c=='.')continue;
                        v[c-'0']++;
                        if(v[c-'0']>1)return 0;
                    }
                }
            }
        }
           return 1; 
        
    }
};