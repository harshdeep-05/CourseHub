class Solution {
public:
    int n;
    int dp[1001];
    /*int solve(vector<int> &cost,int i)
    {
        if(i==n)return 0;
        if(i==n-1 ||i== n-2)return dp[i]=cost[i];
        
        if(dp[i]!=0)return dp[i];
        
        return dp[i]=min(solve(cost,i+1),solve(cost,i+2))+cost[i];
    }
    */
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        //return min(solve(cost,0),solve(cost,1));
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
        
    }
};