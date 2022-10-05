class Solution {
public:
    // static bool comp(vector<int>& a,vector<int>& b)
    // {
    //     return a[2]<b[2];
    // }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // sort(meetings.begin(),meetings.end(),comp);
        vector<vector<pair<int,int>>> adj(n);
        for(auto v:meetings)
        {
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
        }
        // map<int,int> vis;
        vector<int> vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,firstPerson});
        q.push({0,0});
        // vis[firstPerson]=1;
        // vis[0]=1;
        while(!q.empty())
        {
            auto [time,person]=q.top();
            q.pop();
            if(vis[person])continue;
            vis[person]=1;
            for(auto v:adj[person])
            {
                if(!vis[v.first] && time<=v.second)
                    q.push({v.second,v.first});
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i])ans.push_back(i);
        }
        return ans;
    }
};