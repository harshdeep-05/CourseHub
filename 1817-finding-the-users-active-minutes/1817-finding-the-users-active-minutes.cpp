class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k,0);
        map<int,set<int>> m;
        for(auto i:logs)
        {
            m[i[0]].insert(i[1]);
        }
        map<int,int> mp;
        for(auto i:m)
        {
            mp[i.second.size()]++;
        }
        for(auto i:mp)
        {
            ans[i.first-1]=i.second;
        }
        return ans;
    }
};