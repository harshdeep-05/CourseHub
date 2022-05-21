class Solution {
public:
    int dp[10001][13];
    int solve(vector<int>& coins, int amount,int n)
    {
        if(n==0 || amount ==0)
        {
            if(amount==0)return 0;
            else return INT_MAX-1;
        }
        if(dp[amount][n]!=-1)return dp[amount][n];
        if(coins[n-1]>amount)return dp[amount][n]=solve(coins,amount,n-1);
        return dp[amount][n]=min(solve(coins,amount-coins[n-1],n)+1,solve(coins,amount,n-1));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int ans=solve(coins,amount,coins.size());
        if(ans==INT_MAX-1)return -1;
        return ans;
    }
};