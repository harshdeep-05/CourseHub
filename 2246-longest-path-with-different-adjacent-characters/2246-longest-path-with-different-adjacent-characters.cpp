class Solution {
public:
    
    void dfs(int v, int d, vector<vector<int>>& adj, vector<int>& comp, vector<int>& dis) {
        dis[v] = d;
        comp.push_back(v);
        for(int i: adj[v]) {
            if(dis[i] == -1) {
                dfs(i, d + 1, adj, comp, dis);
            }
        }
        
        
    }
    int longestPath(vector<int>& par, string s) {
        int n = s.length();
        vector<vector<int>> adj(n);
        
        for(int i = 1; i < n; i++) {
            if(s[par[i]] != s[i]) {
                adj[i].push_back(par[i]);
                adj[par[i]].push_back(i);
            }
        }
        
        vector<int> dis(n,-1);
        // int ans = 1;
        for(int i = 0; i < n; i++) {
            vector<int> comp;
            if(dis[i] == -1) {
                dfs(i, 0, adj, comp, dis);
                int root = i;
                for(int j: comp) {
                    if(dis[root] < dis[j]) {
                        root = j;
                    }
                    // dis[j] = -1;
                }
                for(int j: comp) dis[j] = -1;
                comp.clear();
                dfs(root, 1, adj, comp, dis);
                
            }
        }
        
        return *max_element(dis.begin(), dis.end());
    }
};