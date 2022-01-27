class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),c=0;
        int row_start=0,row_end=m-1;
        int col_start=0,col_end=n-1;
        vector<int> ans;
        while(row_start<=row_end && col_start<=col_end)
        {
            for(int j=col_start;j<=col_end;j++)
            {
                ans.push_back(matrix[row_start][j]);
                c++;
            }
            if(c >= m*n) break;
            row_start++;
            for(int i=row_start;i<=row_end;i++)
            {
                ans.push_back(matrix[i][col_end]);
                c++;
            }
            col_end--;
            if(c >= m*n) break;
            for(int j=col_end;j>=col_start;j--)
            {
                ans.push_back(matrix[row_end][j]);
                c++;
            }
            row_end--;
            if(c >= m*n) break;
            for(int i=row_end;i>=row_start;i--)
            {
                ans.push_back(matrix[i][col_start]);
                c++;
            }
            col_start++;
            if(c >= m*n) break;
        }
        
        return ans;
    }
};