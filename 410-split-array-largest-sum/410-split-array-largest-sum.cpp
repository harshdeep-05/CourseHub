class Solution {
public:
    int dp[1001][51];
    int n;
    int solve(vector<int> &pre,int i,int m)
    {
        if(dp[i][m]!=-1)return dp[i][m];
        if(m==1)return dp[i][m]=pre[n]-pre[i];
        
        
        int ans=INT_MAX;
        for(int j=i;j<=n-m;j++)
        {
            int sum=pre[j+1]-pre[i];
            int mx=max(sum,solve(pre,j+1,m-1));
            
            ans=min(ans,mx);
            
            if(sum>=ans)break;
        }
        return dp[i][m]=ans;
        
    }
    int splitArray(vector<int>& nums, int m) {
        n=nums.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1]=nums[i]+pre[i];
        }
        memset(dp,-1,sizeof dp);
        return solve(pre,0,m);
        
    }
};