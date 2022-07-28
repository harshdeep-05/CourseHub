class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)return nums[0];
        if(k%2 && n==1)return -1;
        
        int ans=-1;
        for(int i=0;i<min(k-1,n);i++)
            ans=max(ans,nums[i]);
        if(k<n)ans=max(ans,nums[k]);
        return ans;
    }
};