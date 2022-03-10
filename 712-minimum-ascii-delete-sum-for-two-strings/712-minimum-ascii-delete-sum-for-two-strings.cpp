class Solution {
public:
    /*
    int solve(string a,string b,int i,int j)
    {
        if(i==a.size() || j==b.size())return 0;
        
        if(a[i]==b[j])return solve(a,b,i+1,j+1);
        return min(solve(a,b,i+1,j)+a[i],solve(a,b,i,j+1)+b[j]);
    }
    */
    int minimumDeleteSum(string s1, string s2) {
        //return solve(s1,s2,0,0);
        
        int n=s1.size(),m=s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+s1[i-1]+s2[j-1];
                    
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans=0;
        for(auto c:s1)ans+=c;
        for(auto c:s2)ans+=c;
        
        return ans-dp[n][m];
        }
};