class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        
        int s=abs(sum)/2;
        int dp[n+1][s+1];
        
        for(int i=0;i<=s;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(abs(arr[i-1])>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
        int ans=INT_MAX;
        
        for(int i=0;i<=s;i++)
        {
            if(dp[n][i])ans=min(ans,sum-2*i);
        }
        
        return ans;
            
    }
};