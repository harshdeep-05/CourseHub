class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        int row=0,col=0,row_e=n-1,col_e=n-1,q=1;
        while(row<=row_e && col<=col_e)
        {
            for(int i=col;i<=col_e;i++)v[row][i]=q++;
            if(q>n*n)break;
            row++;
            for(int i=row;i<=row_e;i++)v[i][col_e]=q++;
            if(q>n*n)break;
            col_e--;
            for(int i=col_e;i>=col;i--)v[row_e][i]=q++;
            if(q>n*n)break;
            row_e--;
            for(int i=row_e;i>=row;i--)v[i][col]=q++;
            if(q>n*n)break;
            col++;
            
        }
        return v;
    }
};