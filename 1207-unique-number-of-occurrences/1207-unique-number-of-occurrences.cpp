class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr)m[i]++;
        unordered_map<int,int> mp;
        for(auto i:m)
        {
            mp[i.second]++;
            if(mp[i.second]>1)return false;
        }
        return true;
    }
};