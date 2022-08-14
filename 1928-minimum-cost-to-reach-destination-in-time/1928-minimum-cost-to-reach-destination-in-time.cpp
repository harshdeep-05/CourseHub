class Solution {
public:
    int dp[1001][1001];
    int dfs(int u,int k,vector<vector<pair<int,int>>> &graph,vector<int>& fees)
    {
        int n=fees.size();
        if(u==n-1)
            return fees[n-1];
        
        if(dp[u][k]!=-1)return dp[u][k];
        int mi=INT_MAX;
        for(auto &v:graph[u])
        {
            if(v.second>k)continue;
            int a=dfs(v.first,k-v.second,graph,fees);
            if(a!=INT_MAX)
                mi=min(mi,a+fees[u]);
        }
        return dp[u][k]=mi;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>> graph(n);
        for(auto &i:edges)
        {
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }
        memset(dp,-1,sizeof dp);
        dfs(0,maxTime,graph,passingFees);
        return (dp[0][maxTime]==INT_MAX)?-1:dp[0][maxTime];
    }
};