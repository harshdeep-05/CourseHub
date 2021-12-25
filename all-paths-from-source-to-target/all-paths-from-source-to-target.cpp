class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(vector<vector<int>>& graph,vector<int> &cur,int node)
    {
        cur.push_back(node);
        if(node==n-1)
        {
            ans.push_back(cur);
        }
        else
        {
            for(auto i:graph[node])dfs(graph,cur,i);
        }
        cur.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        vector<int> cur;
        dfs(graph,cur,0);
        
        return ans;
    }
};