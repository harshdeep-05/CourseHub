class Solution {
public:
    int dp[51][51];
    int solve(vector<vector<int>>& costs,int person,int a,int b)
    {
        if(person<0)return 0;
        if(dp[a][b]!=-1)return dp[a][b];
        if(a==0)return dp[a][b]=solve(costs,person-1,a,b-1)+costs[person][1];
        if(b==0)return dp[a][b]=solve(costs,person-1,a-1,b)+costs[person][0];
        
        return dp[a][b]=min(solve(costs,person-1,a-1,b)+costs[person][0],
                solve(costs,person-1,a,b-1)+costs[person][1]);
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        memset(dp,-1,sizeof dp);
        return solve(costs,n-1,n/2,n/2);
    }
};