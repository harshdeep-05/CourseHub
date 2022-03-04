class Solution {
public:
    
    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,int node,int par)
    {
        if(vis[node])return true;
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(i!=par && dfs(adj,vis,i,node))return true;
        }
        return false;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            vector<bool> vis(n,0);
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(dfs(adj,vis,u,-1))return i;
        }
        
        return {};
    }
};