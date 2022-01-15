class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto i:nums)sum+=i;
        if(sum%2)return 0;
        sum/=2;
        
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        
        for(auto i:nums)
        {
            for(int j=sum;j>=i;j--)
            {
                dp[j]=dp[j]||dp[j-i];
            }
        }
        return dp[sum];
        
    }
};