class Solution {
    int ans=0;
    void dfs(int node,vector<vector<pair<int,int>>> &graph,vector<int>&vis,
             vector<int> &values,int cur,int maxTime)
    {
        if(!vis[node])
            cur+=values[node];
        if(node==0)ans=max(ans,cur);
        
        vis[node]++;
        for(auto v:graph[node])
        {
            auto [child,time]=v;
            if(time<=maxTime)
            {
                dfs(child,graph,vis,values,cur,maxTime-time);
            }
        }
        vis[node]--;
    }
public:
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime)     {
        int n=values.size();
        vector<vector<pair<int,int>>> graph(n);
        for(auto &i:edges)
        {
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }
        vector<int> vis(n,0);
        dfs(0,graph,vis,values,0,maxTime);
        return ans;
        
    }
};