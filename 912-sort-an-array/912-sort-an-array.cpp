class Solution {
public:
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
    
    void mergeSort(vector<int> &a,int l,int r)
    {
        if(l>=r)return;
        
        int m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        
        merge(a,l,m,r);
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};