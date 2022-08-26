class Solution {
public:
    int dp[10001][101];
    int solve(int egg,int n)
    {
        if(dp[n][egg]!=-1)
            return dp[n][egg];
        
        if(n<=1 || egg==1)
            return n;
        
        int ans=n;
//         for(int k=1;k<=n;k++)
//         {
//             int x1=dp[k-1][egg-1];
//             int x2=dp[n-k][egg];
//             if(x1==-1)
//             {
//                 x1=solve(egg-1,k-1);
//                 dp[k-1][egg-1]=x1;
//             }
//             if(x2==-1)
//             {
//                 x2=solve(egg,n-k);
//                 dp[n-k][egg]=x2;
//             }
            
//             int temp=1+max(x1,x2);
//             ans=min(ans,temp);
//         }
        
        int l=1,r=n;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int low=solve(egg-1,m-1);
            int high=solve(egg,n-m);
            
            if(low<high)
            {
                l=m+1;
            }
            else r=m-1;
            
            int temp=1+max(low,high);
            ans=min(ans,temp);
        }
        
        return dp[n][egg]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof dp);
        return solve(k,n);
    }
};