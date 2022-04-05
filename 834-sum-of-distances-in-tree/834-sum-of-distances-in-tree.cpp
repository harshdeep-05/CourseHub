class Solution {
public:
    vector<int> ans,count;
    int N;
    void dfs(int node,int par,vector<vector<int>> &adj)
    {
        for(auto child:adj[node])
        {
            if(child!=par)
            {
                dfs(child,node,adj);
                count[node]+=count[child];
                ans[node]+=ans[child]+count[child];
            }
        }
        count[node]++;
    }
    void dfs2(int node,int par,vector<vector<int>> &adj)
    {
        for(auto child:adj[node])
        {
            if(child!=par)
            {
                ans[child]=ans[node]-count[child]+N-count[child];
                dfs2(child,node,adj);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        N=n;
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        ans.resize(n);
        count.resize(n);
        dfs(0,-1,adj);
        dfs2(0,-1,adj);
        
        return ans;
    }
};