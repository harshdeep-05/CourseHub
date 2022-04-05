class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=n-1;
        while(nums[l]+nums[r]!=target)
        {
            if(nums[l]+nums[r]>target)r--;
            else l++;
        }
        return {l+1,r+1};
    }
};