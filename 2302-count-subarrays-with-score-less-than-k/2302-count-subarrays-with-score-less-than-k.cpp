class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,n=nums.size(),start=0,end=0,sum=0;
        while(end<n)
        {
            sum+=nums[end];
            while(sum*(end-start+1)>=k)
            {
                sum-=nums[start++];
            }
            ans+=end-start+1;
            end++;
        }
        return ans;
    }
};