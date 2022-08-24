class Solution {
public:
    int countOrders(int n) {
        const int mod=1e9+7;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            long long sum=i*(2*i-1);
            sum*=dp[i-1];
            sum%=mod;
            dp[i]=sum;
        }
        return dp[n];
    }
};