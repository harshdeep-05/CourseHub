class Solution {
public:
    int dp[1001];
    int solve(vector<int>& cost,int i)
    {
        if(i>=cost.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        return dp[i]=min(solve(cost,i+1),
                   solve(cost,i+2))+cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof dp);
        return min(solve(cost,0),solve(cost,1));
        /*
        int n=cost.size();
        int dp[n+1];
        dp[0]=0;
        dp[1]=min(cost[0],cost[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+cost[i-1];
        }
        return dp[n-1];
        */
    }
};