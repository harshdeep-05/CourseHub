class Solution {
public:
    int MAX_COST=1e6+1;
    int dp[101][101][21];
    int solve(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,
              int n_cnt,int index,int pre_color)
    {
        if(index== m && n_cnt==target)
            return 0;
        if(index==m || n_cnt>target)
            return MAX_COST;
        
        if(dp[n_cnt][index][pre_color]!=-1)return dp[n_cnt][index][pre_color];
        
        int cur_cost=MAX_COST;
        if(houses[index]!=0)
        {
            int cnt=n_cnt+(houses[index]!=pre_color);
            cur_cost=solve(houses,cost,m,n,target,cnt,index+1,houses[index]);
        }
        else{
        for(int j=0;j<n;j++)
        {
            int cnt=n_cnt+(pre_color!=j+1);
            cur_cost=min(cur_cost,solve(houses,cost,m,n,target,cnt,index+1,j+1)+cost[index][j]);
        }
        }
        return dp[n_cnt][index][pre_color]=cur_cost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int ans=MAX_COST;
        memset(dp,-1,sizeof dp);
        ans=solve(houses,cost,m,n,target,0,0,0);
        if(ans==MAX_COST)return -1;
        return ans;
        
    }
};