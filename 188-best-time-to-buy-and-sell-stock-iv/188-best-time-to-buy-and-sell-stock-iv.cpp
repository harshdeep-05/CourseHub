class Solution {
public:
    int dp[101][1001][2];
    int solve(int k,vector<int>& prices,int i,int buy)
    {
        if(i==prices.size() || k==0)return 0;
        
        if(dp[k][i][buy]!=-1)return dp[k][i][buy];
        int ans=0;
        if(buy==0)
        {
            ans=max(solve(k,prices,i+1,1)-prices[i], //buy
                    solve(k,prices,i+1,0)); //not buy
        }
        if(buy==1) 
        {
            ans=max(solve(k-1,prices,i+1,0)+prices[i], //sell
                    solve(k,prices,i+1,1)); //not sell
        }
        return dp[k][i][buy]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(k,prices,0,0);
    }
};