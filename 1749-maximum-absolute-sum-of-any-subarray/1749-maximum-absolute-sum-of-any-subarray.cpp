class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=max(nums[i],sum+nums[i]);
            max_sum=max(sum,max_sum);
        }
        int min_sum=INT_MAX,s=0;
        for(int i=0;i<nums.size();i++)
        {
            s=min(nums[i],s+nums[i]);
            min_sum=min(s,min_sum);
        }
        return max(abs(max_sum),abs(min_sum));
    }
};