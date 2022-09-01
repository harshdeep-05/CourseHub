class Solution {
public:
    // int f[26];
    vector<int> ans;
    vector<int> solve(vector<vector<int>>& graph,string &labels,int node,vector<bool>&vis)
    {
        vector<int> f(26,0); 
        vis[node]=1;
        for(auto x:graph[node])
        {
            if(!vis[x])
            {
                vector<int> tmp=solve(graph,labels,x,vis);
                for(int i=0;i<26;i++)
                    f[i]+=tmp[i];
            }
        }
        
        f[labels[node]-'a']++;
        ans[node]=f[labels[node]-'a'];            
        return f;
        
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        ans=vector<int> (n,1);
        for(auto i:edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,0);
        solve(graph,labels,0,vis);
        return ans;
    }
};