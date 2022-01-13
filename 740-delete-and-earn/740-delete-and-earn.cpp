class Solution {
public:
    int dp[20001],n;
    int solve(vector<int>&nums,int i)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        
        int x=nums[i],j=i+1,sum=nums[i];
        while(j<n && x==nums[j])j++,sum+=x;
        while(j<n && x==nums[j]-1)j++;
        
        return dp[i]=max(sum+solve(nums,j),solve(nums,i+1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof dp);
        return solve(nums,0);
        
    }
};