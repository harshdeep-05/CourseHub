class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0,j=0,ans=0;
        long sum=0;
        while(j<n)
        {
            sum+=nums[j];
            while(i<j && sum+k<(long)nums[j]*(j-i+1))sum-=nums[i++];
            ans=max(ans,j-i+1);
            j++;
            
        }
        return ans;
    }
};