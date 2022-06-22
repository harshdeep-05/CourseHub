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
    //Merge SOrt
    void merge(vector<int> &arr,int l,int m,int r)
    {
        int Lsz = m-l+1 , Rsz = r-m;
         int leftarr[Lsz] , rightarr[Rsz];
         
         for(int i = 0; i < Lsz; i++)
            leftarr[i] = arr[l+i];
         
         for(int i = 0; i < Rsz; i++)
            rightarr[i] = arr[m+1+i];
         
         int lptr = 0 , rptr = 0 , indx = l;
         
         while(lptr < Lsz && rptr < Rsz){
             if(leftarr[lptr] < rightarr[rptr]){
                 arr[indx] = leftarr[lptr];
                 lptr++;
             }
             else{
                 arr[indx] = rightarr[rptr];
                 rptr++;
             }
             indx++;
         }
         
         while(lptr < Lsz){
             arr[indx] = leftarr[lptr];
             lptr++;
             indx++;
         }
         while(rptr < Rsz){
             arr[indx] = rightarr[rptr];
             rptr++;
             indx++;
         }
    }
    void merge_sort(vector<int> &v,int l,int r)
    {
        if(l>=r)return;
        
        int mid=l+(r-l)/2;
        merge_sort(v,l,mid);
        merge_sort(v,mid+1,r);
        return merge(v,l,mid,r);
        
    }
    
    void print(vector<int> &v)
    {
        for(auto i:v)cout<<i<<" ";
        cout<<"\n";
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        //bubble_sort(nums);
        //selection_sort(nums);
        //insertion_sort(nums);
        merge_sort(nums,0,n-1);
        //print(nums);
        return nums[n-k];
    }
};