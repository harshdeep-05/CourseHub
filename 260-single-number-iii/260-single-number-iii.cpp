class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size(),x=0;
        for(auto i:nums)x^=i;
        int mask=1;
        while(1)
        {
            if((mask&x)==0)mask=mask<<1;
            else break;
        }
        int a=0,b=0;
        for(auto i:nums)
        {
            if((i&mask)==0)a^=i;
            else b^=i;
        }
        return {a,b};
    }
};