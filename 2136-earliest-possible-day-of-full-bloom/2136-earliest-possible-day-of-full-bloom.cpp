class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>> v;
        int n=g.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({g[i],p[i]});
        }
        sort(v.rbegin(),v.rend());
        int ans=0,days=0;
        for(int i=0;i<n;i++)
        {
            days+=v[i].second;
            ans=max(ans,days+v[i].first);
        }
        // ans+=v.back().first;
        return ans;
    }
};