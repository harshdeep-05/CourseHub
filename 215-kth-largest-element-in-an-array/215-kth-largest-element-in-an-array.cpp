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
    //selection sort
    void selection_sort(vector<int> &a)
    {
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            int mi=a[i],index=i;
            for(int j=i;j<n;j++)
            {
                mi=min(mi,a[j]);
                if(mi==a[j])index=j;
            }
            swap(a[i],a[index]);
        }
    }
    //inertion sort
    void insertion_sort(vector<int> &nums)
    {
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int cur=nums[i],j=i-1;
            while(j>=0 && nums[j]>cur){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=cur;
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        //bubble_sort(nums);
        selection_sort(nums);
        
        return nums[n-k];
    }
};