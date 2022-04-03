class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i=n-2;
        while(i>=0 && nums[i+1]<=nums[i])i--;
        
        if(i>=0)
        {
            int j=n-1;
            while(nums[j]<=nums[i])j--;
            swap(nums[i],nums[j]);
        }
        i++;
        int j=n-1;
        while(i<j)
        {
            swap(nums[i++],nums[j--]);
        }
        return;
        
    }
};