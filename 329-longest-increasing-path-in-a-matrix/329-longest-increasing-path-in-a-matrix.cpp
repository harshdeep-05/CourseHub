class Solution {
public:
    int dp[201][201];
    int dfs(int i,int j,vector<vector<int>>& mat,int pre)
    {
        int m=mat.size(),n=mat[0].size();
        if(i<0 || j<0 || i>=m || j>=n || mat[i][j]<=pre)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int l=dfs(i-1,j,mat,mat[i][j]);
        int r=dfs(i+1,j,mat,mat[i][j]);
        int u=dfs(i,j-1,mat,mat[i][j]);
        int d=dfs(i,j+1,mat,mat[i][j]);
        
        return dp[i][j]=max({l,r,u,d})+1;
        
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        memset(dp,-1,sizeof dp);
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dfs(i,j,matrix,-1));
            }
        }
        return ans;
        
    }
};