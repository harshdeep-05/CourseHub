class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<vector<int>> s;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            if(m.find(i+k)!=m.end())
            {
                s.insert({i,i+k});
            }
            if(m.find(i-k)!=m.end())
            {
                s.insert({i-k,i});
            }
            m[i]=i;
        }
        return s.size();
    }
};