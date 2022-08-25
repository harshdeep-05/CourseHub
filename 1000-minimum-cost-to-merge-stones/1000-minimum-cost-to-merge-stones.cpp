class Solution {
public:
    int dp[31][31];
    int solve(vector<int>&stones,int l,int r,int k)
    {
        if(l>=r)
            return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=INT_MAX;
        for(int i=l;i<r;i+=k-1)
        {
            ans=min(ans,solve(stones,l,i,k)+solve(stones,i+1,r,k));
        }
        if((r-l)%(k-1)==0)
        {
            ans+=stones[r+1]-stones[l];
        }
        return dp[l][r]=ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        memset(dp,-1,sizeof dp);
        if((n-1)%(k-1) != 0) return -1;
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+stones[i-1];
        }   
        return solve(pre,0,n-1,k);
    }
};