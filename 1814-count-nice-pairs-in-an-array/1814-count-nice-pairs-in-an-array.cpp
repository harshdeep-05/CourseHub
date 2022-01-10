class Solution {
public:
    int mod=1e9+7;
    int rev(int num)
    {
        int ans=0;
        while(num)
        {
            ans=ans*10+num%10;
            num/=10;
        }
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            int x=i-rev(i);
            if(m.find(x)!=m.end())ans=(ans+m[x])%mod;
            m[x]++;
        }
        return ans;
    }
};