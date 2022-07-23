class Solution {
public:
    bool check(vector<int> &v,vector<int> &c)
    {
        return pow(v[0]-c[0],2)+pow(v[1]-c[1],2)<=pow(v[2],2);
    }
    void dfs(vector<int> graph[],int node,vector<bool> &vis,int &cnt)
    {
        vis[node]=true;
        for(auto v:graph[node])
        {
            if(!vis[v]){
                cnt++;
                dfs(graph,v,vis,cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> graph[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                if(check(bombs[i],bombs[j]))
                    graph[i].push_back(j);
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