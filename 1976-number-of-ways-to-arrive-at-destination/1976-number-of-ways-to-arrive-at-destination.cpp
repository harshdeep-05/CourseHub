class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> graph(n);
        for(auto i:roads)
        {
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }
        vector<ll> dis(n,LONG_MAX),dp(n,0);
        dis[0]=0;
        dp[0]=1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
        q.push({0,0});
        while(!q.empty())
        {
            auto [distance,node]=q.top();
            q.pop();
            for(auto child:graph[node])
            {
                if(dis[child.first]>distance+child.second)
                {
                    dis[child.first]=distance+child.second;
                    q.push({dis[child.first],child.first});
                    dp[child.first]=dp[node];
                    
                }
                else if(dis[child.first]==distance+child.second){
                    dp[child.first]=(dp[child.first]+dp[node])%mod;
                }
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        return dp[n-1];
            
    }
};