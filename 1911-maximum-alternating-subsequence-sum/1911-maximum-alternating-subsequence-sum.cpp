class Solution {
public:
    long long dp[100001][2];
    long long solve(vector<int>& nums,int flag,int i)
    {
        if(i==nums.size())return 0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        if(flag==0)
        {
            return dp[i][flag]=max(solve(nums,0,i+1),solve(nums,1,i+1)+nums[i]);
        }
        else
            return dp[i][flag]=max(solve(nums,1,i+1),solve(nums,0,i+1)-nums[i]);
        
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(nums,0,0);
    }
};