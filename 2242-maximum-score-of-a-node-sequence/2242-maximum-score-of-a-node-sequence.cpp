class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();
        vector<vector<pair<int,int>>>G(n);
        for(auto &x:edges)
        {
            G[x[0]].push_back({scores[x[1]],x[1]});
            G[x[1]].push_back({scores[x[0]],x[0]});
        }
        for(int i=0;i<n;i++)
            sort(G[i].begin(),G[i].end(),greater<pair<int,int>>());
        int ans=-1;
        for(auto &x:edges)
        {
            int left=x[0],right=x[1];
            int cur=scores[left]+scores[right];
            int sz1=G[left].size(),sz2=G[right].size();
            for(int i=0;i<min(3,sz1);i++)
                for(int j=0;j<min(3,sz2);j++)
                {
                    if(G[left][i].second==left||G[left][i].second==right||G[left][i].second==G[right][j].second)
                        continue;
                    if(G[right][j].second==left||G[right][j].second==right||G[right][j].second==G[left][i].second)
                        continue;
                    ans=max(ans,cur+G[left][i].first+G[right][j].first);
                }
        }
        return ans;
        
    }
};