class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int row=0;row<m;row++)
        {
            int i=row,j=0;
            priority_queue<int> q;
            while(i<m && j<n)
            {
                q.push(mat[i++][j++]);
            }
            while(!q.empty())
            {
                mat[--i][--j]=q.top();
                q.pop();
            }
        }
        for(int col=1;col<n;col++)
        {
            int i=0,j=col;
            priority_queue<int> q;
            while(i<m && j<n)
            {
                q.push(mat[i++][j++]);
            }
            while(!q.empty())
            {
                mat[--i][--j]=q.top();
                q.pop();
            }
        }
        return mat;
    }
};