class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        if(m==0)return 0;
        int i=m-1,j=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j]==target)return 1;
            else if(matrix[i][j]>target)i--;
            else j++;
        }
        return 0;
    }
};