class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();
        vector<vector<pair<int,int>>> graph(n);
        for(auto &v:edges)
        {
            graph[v[0]].push_back({scores[v[1]],v[1]});
            graph[v[1]].push_back({scores[v[0]],v[0]});
        }
        for(auto &v:graph)
        {
            sort(v.begin(),v.end(),greater<pair<int,int>> ());
        }
        int ans=-1;
        for(auto x:edges)
        {
            int u=x[0],v=x[1];
            int sz1=graph[u].size(),sz2=graph[v].size();
            int cur=scores[u]+scores[v];
            for(int i=0;i<min(3,sz1);i++)
            {
                for(int j=0;j<min(3,sz2);j++)
                {
                    if(graph[u][i].second!=graph[v][j].second && graph[u][i].second!=v && graph[v][j].second!=u)
                    {
                        ans=max(ans,cur+graph[u][i].first+graph[v][j].first);
                    }
                }
            }
        }
        return ans;
        
    }
};