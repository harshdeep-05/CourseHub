class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &graph,int node,int ancestor)
    {
        for(auto v:graph[node])
        {
            if(ans[v].empty() || ans[v].back()!=ancestor)
            {
                ans[v].push_back(ancestor);
                dfs(graph,v,ancestor);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        ans=vector<vector<int>> (n);
        for(auto v:edges)
        {
            graph[v[0]].push_back(v[1]);
        }
        for(int i=0;i<n;i++)
        {
            dfs(graph,i,i);
        }
        return ans;
        
    }
};