class Solution {
public:
    bool check(vector<int> &v,vector<int> &c)
    {
        long long x=pow(v[0]-c[0],2);
        long long y=pow(v[1]-c[1],2);
        return (x+y<=pow(v[2],2));
    }
    void dfs(vector<vector<int>> &graph,int node,vector<bool> &vis,int &cnt)
    {
        vis[node]=true;
        for(int j=0;j<graph.size();j++)
        {
            if(!vis[j] && graph[node][j]==1){
                cnt++;
                dfs(graph,j,vis,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> graph(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check(bombs[i],bombs[j]))
                    graph[i][j]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            vector<bool> vis(n,0);
            dfs(graph,i,vis,cnt);
            ans=max(cnt,ans);
        }
        return ans;
    }
};