class Solution {
public:
    long long dp[201][201];
    long long solve(vector<vector<long long>> &v,int m,int n)
    {
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(m==1 && n==1)
        {
            return dp[m][n]=v[m][n];
        }
        
        long long ans=v[m][n];
        for(int i=1;i<=m/2;i++)
        {
            ans=max(ans,solve(v,i,n)+solve(v,m-i,n));
        }
        for(int i=1;i<=n/2;i++)
        {
            ans=max(ans,solve(v,m,i)+solve(v,m,n-i));
        }
        return dp[m][n]=ans;
            
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> v(m+1,vector<long long>(n+1,0));
        memset(dp,-1,sizeof dp);
        for(auto x:prices)
        {
            v[x[0]][x[1]]=x[2];
        }
        return solve(v,m,n);
    }
};