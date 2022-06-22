class Solution {
public:
    //bubble sort
    void bubble_sort(vector<int> &nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(nums[j]>nums[j+1])swap(nums[j],nums[j+1]);
            }
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        bubble_sort(nums);
        int n=nums.size();
        return nums[n-k];
    }
};