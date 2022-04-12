class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums1, vector<int>& nums2,int i,bool swapped,int prev1,int prev2)
    {
        if(i==nums1.size())return 0;
        if(dp[i][swapped]!=-1)return dp[i][swapped];
        int ans=INT_MAX;
        
        if(nums1[i]>prev1 && nums2[i]>prev2)
            ans=solve(nums1,nums2,i+1,0,nums1[i],nums2[i]);
        
        swap(nums1[i],nums2[i]);
        if(nums1[i]>prev1 && nums2[i]>prev2)
            ans=min(ans,1+solve(nums1,nums2,i+1,1,nums1[i],nums2[i]));
        
        swap(nums1[i],nums2[i]);
        return dp[i][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(2,-1));
        return solve(nums1,nums2,0,0,-1,-1);
    }
};