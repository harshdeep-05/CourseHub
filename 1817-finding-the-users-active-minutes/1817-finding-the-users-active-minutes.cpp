class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k,0);
        map<int,set<int>> m;
        for(auto i:logs)
        {
            m[i[0]].insert(i[1]);
        }
        for(auto i:m)
        {
            ans[i.second.size()-1]++;
        }
        return ans;
    }
};