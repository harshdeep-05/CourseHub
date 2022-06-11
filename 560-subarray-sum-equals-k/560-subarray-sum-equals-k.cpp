class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),count=0;
        unordered_map<int,int> m;
        int sum=0;
        m[sum]=1;
        for(auto i:nums)
        {
            sum+=i;
            int target=sum-k;
            if(m.find(target)!=m.end())count+=m[target];
            m[sum]++;
        }
        
        return count;
    }
};