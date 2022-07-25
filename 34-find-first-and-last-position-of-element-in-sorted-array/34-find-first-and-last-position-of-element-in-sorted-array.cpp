class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int low=-1,high=-1;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                high=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                low=mid;
                r=mid-1;
            }
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return {low,high};
    }
};