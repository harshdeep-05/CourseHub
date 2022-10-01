class Solution {
public:
    int dp[101][101][101];
    int solve(string &s,int i,int j,int len)
    {
        if(i>j)
            return 0;
        if(dp[i][j][len]!=-1)return dp[i][j][len];
        int ans=solve(s,i+1,j,0)+1;
        for(int k=i+1;k<=j;k++)
        {
            if(s[k]==s[i])
                ans=min(ans,solve(s,i+1,k-1,0)+solve(s,k,j,len+1));
        }
        return dp[i][j][len]=ans;
    }
    int strangePrinter(string s) {
        int n=s.size();
        memset(dp,-1,sizeof dp);
        return solve(s,0,n-1,0);
    }
};