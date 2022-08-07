class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> graph[n],rgraph[n];
        for(auto &x:connections)
        {
            graph[x[0]].push_back(x[1]);
            rgraph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            vis[top]=1;
            for(auto i:rgraph[top])
            {
                if(!vis[i])
                {
                    q.push(i);
                }
            }
            for(auto i:graph[top])
            {
                if(!vis[i])
                {
                    ans++;
                    q.push(i);
                }
            }
        }
        return ans;
    }
};