class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=0;
        while(i<m)
        {
            int l=0,r=n-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(matrix[i][mid]==target)return 1;
                else if(matrix[i][mid]<target)l=mid+1;
                else r=mid-1;
            }
            i++;
            
        }
        return 0;
    }
};