class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cur_row=0,m=matrix.size(),n=matrix[0].size();
        while(cur_row<m)
        {
            if(target>matrix[cur_row][n-1]){
                cur_row++;
                continue;
            }
            int l=0,r=n-1;
            while(l<=r)
            {
                int m=l+(r-l)/2;
                if(matrix[cur_row][m]==target)return true;
                if(matrix[cur_row][m]<target)l=m+1;
                else r=m-1;
            }
            return false;
        }
        return false;
    }
};