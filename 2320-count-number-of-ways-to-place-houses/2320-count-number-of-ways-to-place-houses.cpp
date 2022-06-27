class Solution {
public:
    int dp[10001];
    const int mod=1e9+7;
    int solve(int n)
    {
        if(n<0)return 1;
        if(dp[n]!=-1)return dp[n];
        int place=solve(n-2);
        int not_place=solve(n-1);
        
        return dp[n]=(place+not_place)%mod;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof dp);
        solve(n);
        return ((long long)dp[n-1]*dp[n-1])%mod;
    }
};