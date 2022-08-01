class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        unordered_map<long long,long long> m;
        for(int i=0;i<n;i++)
        {
            int x=__gcd(nums[i],k);
            m[x]++;
        }
        for(auto i:m)
        {
            for(auto j:m)
            {
                if((i.first*j.first)%k)continue;
                
                if(i.first==j.first)
                    ans+=(i.second-1)*(j.second);
                else 
                    ans+=(i.second)*(j.second);
            }
        }
        return ans/2;
    }
};