class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        if (!m|| !n) return false;
        int l=0,r=m-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(target>matrix[m][n-1])l=m+1;
            else if(target<matrix[m][0])r=m-1;
            else 
            {
                l=m;
                break;
            }
        }
        int cur_row=l;
            l=0;
            r=n-1;
            while(l<=r)
            {
                int m=l+(r-l)/2;
                if(matrix[cur_row][m]==target)return true;
                if(matrix[cur_row][m]<target)l=m+1;
                else r=m-1;
            }
            return false;
    }
};