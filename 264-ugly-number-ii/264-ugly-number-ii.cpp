class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=6)return n;
        int a=0,b=0,c=0;
        int dp[n];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(2*dp[a],min(3*dp[b],5*dp[c]));
            if(dp[i]==2*dp[a])a++;
            if(dp[i]==3*dp[b])b++;
            if(dp[i]==5*dp[c])c++;
            
            cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};