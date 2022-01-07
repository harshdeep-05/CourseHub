class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        int ans=0;
        vector<int> dist(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:adj[u])
            {
                if(dist[v.first]>dist[u]+v.second)
                {
                    dist[v.first]=dist[u]+v.second;
                    q.push(v.first);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)return -1;
            ans=max(ans,dist[i]);
        }
            
        return ans;
        
    }
};