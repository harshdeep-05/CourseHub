class Solution {
public:
    double bfs(string src,string dest,
               unordered_map<string,vector<pair<string,double>>> &graph)
    {
        unordered_map<string,bool> vis;
        queue<pair<string,double>> q;
        q.push({src,1});
        vis[src]=true;
        while(!q.empty())
        {
            auto s=q.front();
            q.pop();
            for(auto v:graph[s.first])
            {
                if(v.first==dest)
                {
                    return v.second*s.second;
                }
                if(vis.find(v.first)!=vis.end())continue;
                
                vis[v.first]=true;
                q.push({v.first,v.second*s.second});
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;
        int i=0;
        for(auto &s:equations)
        {
            graph[s[0]].push_back({s[1],values[i]});
            graph[s[1]].push_back({s[0],1.0/values[i]});
            i++;
        }
        int n=queries.size();
        vector<double> ans(n,-1.0);
        i=0;
        for(auto &s:queries)
        {
            ans[i++]=bfs(s[0],s[1],graph);
            
        }
        return ans;
    }
};