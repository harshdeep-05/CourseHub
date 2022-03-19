class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size(),s=n/2;
        sort(nums.begin(),nums.end());
        int ans=0,ans2=0;
        for(auto i:nums)
        {
            ans+=abs(i-nums[s]);
        }
        return ans;
    }
};