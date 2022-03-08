class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            if(m.find(i)!=m.end())ans.push_back(i);
            else m[i]=1;
        }
        return ans;
    }
};