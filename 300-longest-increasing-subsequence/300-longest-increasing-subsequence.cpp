class Solution {
public:
    int dp[2505][2505];
    int solve(vector<int> &nums,int n,int prev)
    {
        if(n<0)
            return 0;
        
        if(dp[n][prev]!=-1)
            return dp[n][prev];
        
        int inc=0,no_inc=0;
        
        if(prev==nums.size() || nums[n]<nums[prev])
            inc=1+solve(nums,n-1,n);
        
        no_inc=solve(nums,n-1,prev);
        
        return dp[n][prev]=max(inc,no_inc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof dp);
        return solve(nums,n-1,n);
        
        
    }
};