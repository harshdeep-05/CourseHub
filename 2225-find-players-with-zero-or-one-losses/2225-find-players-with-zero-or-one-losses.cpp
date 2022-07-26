class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> m;
        unordered_map<int,int> win;
        for(auto v:matches)
        {
            m[v[1]]++;
            win[v[0]]++;
        }
        vector<vector<int>> ans(2);
        for(auto i:m)
        {
            if(i.second==1)ans[1].push_back(i.first);
        }
        for(auto i:win)
        {
            if(m.find(i.first)==m.end())
                ans[0].push_back(i.first);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};