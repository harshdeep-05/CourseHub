class Solution {
public:
    int ans=0;
    vector<pair<int,int> > adj[101];
    void dfs(int node,vector<int> &time,int curTime)
    {
        if(curTime>=time[node])return;
        time[node]=curTime;
        for(auto v:adj[node])
        {
            dfs(v.first,time,curTime+v.second);
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        for(auto v:times)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        for (int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        vector<int> time(n+1,INT_MAX);
        dfs(k,time,0);
        ans=INT_MIN;
        for(int i=1;i<=n;i++)ans=max(ans,time[i]);
        return ans==INT_MAX?-1:ans;
    }
};