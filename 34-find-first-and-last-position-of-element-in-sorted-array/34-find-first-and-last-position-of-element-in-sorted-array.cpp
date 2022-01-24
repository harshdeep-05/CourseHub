class Solution {
public:
    int first(vector<int>& nums, int target)
    {
        int l=0,r=nums.size()-1,m,res=-1;
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(nums[m]==target)
            {
                res=m;
                r=m-1;
            }
            else if(nums[m]<target)l=m+1;
            else r=m-1;
        }
        return res;
        
    }
    
    int last(vector<int>& nums, int target)
    {
        int l=0,r=nums.size()-1,m,res=-1;
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(nums[m]==target)
            {
                res=m;
                l=m+1;
            }
            else if(nums[m]<target)l=m+1;
            else r=m-1;
        }
        return res;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),last(nums,target)};
        
        
    }
};