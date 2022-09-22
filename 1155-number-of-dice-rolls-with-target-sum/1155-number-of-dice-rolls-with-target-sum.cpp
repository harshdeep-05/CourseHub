class Solution {
public:
    const int mod=1e9+7;
//     int dp[31][31][1001];
//     int solve(int n,int k,int sum)
//     {
//         if(sum<0)
//             return 0;
//         if(n==0 && sum==0)
//             return 1;
        
//         if(n==0 || k==0)return 0;
        
//         if(dp[n][k][sum]!=-1)
//             return dp[n][k][sum];
        
//         int ans=solve(n,k-1,sum)%mod;
//         if(k<=sum)
//             ans=(ans+solve(n-1,k,sum-k)%mod)%mod;
        
//         return dp[n][k][sum]=ans%mod;
//     }
    int dp[31][1001];
    int solve(int n,int k,int sum)
    {
        if(n==0 && sum==0)
            return 1;
        if(n==0 || sum<=0)
            return 0;
        
        if(dp[n][sum]!=-1)return dp[n][sum];
        
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans=(ans+solve(n-1,k,sum-i))%mod;
        }
        return dp[n][sum]=ans%mod;
            
    }
        
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return solve(n,k,target);
        // return ans%mod;
    }
};