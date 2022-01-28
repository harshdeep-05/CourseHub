class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int dp[m][n],ans=0;
        memset(dp,0,sizeof dp);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j])
                {
                    if(i*j==0)dp[i][j]=matrix[i][j];
                    else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
                ans+=dp[i][j];
            }
            
        }
        return ans;
    }
};