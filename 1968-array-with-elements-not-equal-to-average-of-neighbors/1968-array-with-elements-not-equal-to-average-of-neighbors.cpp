class Solution {
public:
    /*
    int partition(vector<int> &v,int low,int high)
    {
        int pivot=v[high];
        int j=low-1;
        for(int i=low;i<high;i++)
        {
            if(v[i]<pivot)
            {
                j++;
                swap(v[j],v[i]);
            }
        }
        swap(v[j+1],v[high]);
        return j+1;
    }
    void priority_sort(vector<int> &v,int low,int high)
    {
        if(low>=high)return;
        int pi=partition(v,low,high);
        priority_sort(v,low,pi-1);
        priority_sort(v,pi+1,high);
        return;
    }   
    */
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        //priority_sort(nums,0,n-1);
        sort(nums.begin(),nums.end());
        int j=n-1;
        for(int i=1;i<n;i+=2)ans[i]=nums[j--];
        for(int i=0;i<n;i+=2)ans[i]=nums[j--];
        return ans;
    }
};