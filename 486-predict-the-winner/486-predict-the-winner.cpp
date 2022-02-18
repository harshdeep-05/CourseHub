class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size(),dp[n];
        for(int i=n;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)dp[i]=nums[i];
                else 
                {
                    int a=nums[i]-dp[j];
                    int b=nums[j]-dp[j-1];
                    dp[j]=max(a,b);
                }
            }
        }
        return dp[n-1]>=0;
    }
};