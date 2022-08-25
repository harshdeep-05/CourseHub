class Solution {
public:
    int dp[303][303];
    int solve(vector<int>& nums,int l,int r)
    {
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        for(int i=l;i<=r;i++)
        {
            ans=max(ans,solve(nums,l,i-1)+solve(nums,i+1,r)+nums[l-1]*nums[i]*nums[r+1]);
        }
        return  dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return solve(nums,1,n);
    }
};