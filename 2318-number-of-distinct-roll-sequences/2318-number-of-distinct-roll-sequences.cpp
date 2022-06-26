class Solution {
public:
    const int mod=1e9+7;
    int dp[10001][7][7];
    int solve(int index,int pre,int ppre,int n)
    {
        if(index==n)return 1;
        
        if(dp[index][pre][ppre]!=-1)return dp[index][pre][ppre];
        
        int ans=0;
        for(int i=1;i<=6;i++)
        {
            if(i!=pre && i!=ppre && (pre==0 || __gcd(i,pre)==1))
            {
                ans=(ans+solve(index+1,i,pre,n)%mod)%mod;
            }
        }
        return dp[index][pre][ppre]=ans;
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,n);
    }
};