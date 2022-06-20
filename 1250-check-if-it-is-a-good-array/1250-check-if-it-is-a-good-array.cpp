class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd=nums[0];
        for(auto i:nums)gcd=__gcd(i,gcd);
        return (gcd==1);
    }
};