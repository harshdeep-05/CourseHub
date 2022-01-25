class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1)return n;
        int dp[n+1],mx=1;
        dp[0]=0;
        dp[1]=1;
        for(int i=1;2*i+1<=n;i++)
        {
            dp[2*i]=dp[i];
            dp[2*i+1]=dp[i]+dp[i+1];
            mx=max(mx,dp[2*i+1]);
        }
        return mx;
    }
};