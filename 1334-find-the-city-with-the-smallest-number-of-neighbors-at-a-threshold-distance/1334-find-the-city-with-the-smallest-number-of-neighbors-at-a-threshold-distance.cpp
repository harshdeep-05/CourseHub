class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int K) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto &u:edges)
        {
            graph[u[0]].push_back({u[1],u[2]});
            graph[u[1]].push_back({u[0],u[2]});
        }
        int min_city=n,ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,1e7);
            queue<int> q;
            q.push(i);
            dist[i]=0;
            while(!q.empty())
            {
                
                int curr = q.front();
                q.pop();
                for(auto [next,edge] : graph[curr])
                {
                    if(dist[curr]+edge<dist[next])
                    {
                        dist[next] = dist[curr]+edge;
                        q.push(next);
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[j] && dist[j]<=K)
                    count++;
            }
            if(count<=min_city)
            {
                ans=i;
                min_city=count;
            }
            //cout<<city<<" ";
            
        }
        return ans;
        
    }
};