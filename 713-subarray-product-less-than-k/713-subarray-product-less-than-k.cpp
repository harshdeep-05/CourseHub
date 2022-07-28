class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int n=nums.size(),ans=0;
        int prod=1,i=0,j=0;
        
        while(j<n)
        {
            prod*=nums[j];
            while(prod>=k)prod/=nums[i++];
            ans+=j-i+1;
            j++;
        }
        
        return ans;
        
    }
};