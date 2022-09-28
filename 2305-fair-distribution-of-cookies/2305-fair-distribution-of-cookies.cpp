class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n=cookies.size(),sz=1<<n;
        
        vector<vector<int>> dp(k+1,vector<int> (sz,INT_MAX));
        vector<int> sum(sz,0);
        
        for(int mask=0;mask<sz;mask++)
        {
            for(int i=0;i<n;i++)
            {
                if(mask & (1<<i))
                {
                    sum[mask]+=cookies[i];
                }
            }
        }
        
        dp[0][0]=0;
        for(int set=1;set<=k;set++)
        {
            for(int mask=0;mask<sz;mask++)
            {
                for(int i=mask;i>0;i=(i-1)&mask)
                {
                    dp[set][mask]=min(dp[set][mask],max(sum[i],dp[set-1][mask^i]));
                }
            }
        }
        return dp[k][sz-1];
    }
};