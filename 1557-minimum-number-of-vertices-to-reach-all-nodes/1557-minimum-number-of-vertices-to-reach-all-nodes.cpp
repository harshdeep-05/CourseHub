class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //vector<int> adj[n];
        vector<int> in(n,1);
        for(auto i:edges)
        {
            //adj[i[0]].push_back(i[1]);
            in[i[1]]=0;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)if(in[i])ans.push_back(i);
        return ans;
    }
};