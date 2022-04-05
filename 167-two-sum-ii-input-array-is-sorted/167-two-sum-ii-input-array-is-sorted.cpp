class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x=target-nums[i];
            int l=i+1,r=n-1,m;
            while(l<=r)
            {
                m=l+(r-l)/2;
                if(nums[m]==x)return {i+1,m+1};
                else if(nums[m]>x)r=m-1;
                else l=m+1;
            }
        }
        return {};
    }
};