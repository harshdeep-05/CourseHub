class Solution {
public:
    long long ans=-1;
    const int mod=1e9+7;
    void dfs(vector<vector<int>>& v,int i,int j,long long prod)
    {
        int m=v.size(),n=v[0].size();
        if(v[i][j]==0)
        {
            ans=max(ans,(long long)0);
            return;
        }
        prod*=(long long)v[i][j];
        if(i==m-1 && j==n-1)
        {
            ans=max(ans,prod);
            return;
        }
        
        if(i+1<m)dfs(v,i+1,j,prod);
        if(j+1<n)dfs(v,i,j+1,prod);
        return;
    }
    int maxProductPath(vector<vector<int>>& grid) {
        // int prod=1;
        dfs(grid,0,0,1);
        if(ans<0)return -1;
        return ans%mod;
    }
};