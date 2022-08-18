class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> indegree(n,0);
        vector<int> adj[n];
        vector<int> ans(n,0);
        for(auto i:richer)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
            ans[i]=i;
        }
        // vector<int> topo(n);
        // int idx=0;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            // topo[idx++]=top;
            // cout<<top<<" ";
            for(auto u:adj[top])
            {
                if(quiet[ans[u]]>quiet[ans[top]])
                {
                    ans[u]=ans[top];
                }
                indegree[u]--;
                if(indegree[u]==0)q.push(u);
            }
        }
        
        return ans;
    }
};