class Solution {
public:
    int dfs(int node,vector<long long> &sum,vector<int> adj[],long long &mx)
    {
        int n=sum.size();
        if(adj[node].size()==0)
        {
            sum[node]=n-1;
            mx=max(mx,sum[node]);
            return 1;
        }
        if(adj[node].size()==1)
        {
            int x=dfs(adj[node][0],sum,adj,mx);
            sum[node]=(long long)max(n-x-1,1)*x;
            mx=max(mx,sum[node]);
            return x+1;
        }
        int x=dfs(adj[node][0],sum,adj,mx);
        int y=dfs(adj[node][1],sum,adj,mx);
        sum[node]=(long long)max(n-x-y-1,1)*x*y;
        mx=max(mx,sum[node]);
        return x+y+1;
        
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++)
        {
            adj[parents[i]].push_back(i);
        }
        vector<long long> sum(n);
        long long mx=0;
        dfs(0,sum,adj,mx);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(sum[i]==mx)ans++;
        }
        return ans;
    }
};