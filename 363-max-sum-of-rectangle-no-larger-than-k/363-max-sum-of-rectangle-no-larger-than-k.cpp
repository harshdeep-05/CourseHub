class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        int dp[m+1][n];
        memset(dp,0,sizeof dp);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i+1][j]=dp[i][j]+matrix[i][j];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int l=i+1;l<=m;l++)
            {
                for(int j=0;j<n;j++)
                {
                    int val=0;
                    for(int r=j;r<n;r++)
                    {
                        val+=dp[l][r]-dp[i][r];
                        if(val==k)return k;
                        if(val<k)ans=max(ans,val);
                    }
                }
            }
        }
        return ans;
    }
};