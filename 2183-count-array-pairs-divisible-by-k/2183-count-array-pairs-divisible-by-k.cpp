class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        unordered_map<long long,long long> m;
        for(int i=0;i<n;i++)
        {
            int x=__gcd(nums[i],k);
            int y=k/x;
            if(y==1)ans+=i;
            else
            {
                for(auto j:m)
                {
                    if(j.first%y==0)ans+=j.second;
                }
            }
            m[x]++;
        }
        return ans;
    }
};