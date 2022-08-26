class Solution {
public:
    // int dp[2001][2001];
    bool pal(string &s,int i,int j,vector<vector<int>> &dp)
    {
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans=1;
        int l=i,r=j;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                ans=0;
                break;
            }
            l++;r--;
        }
        return dp[i][j]=ans;
    }
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // memset(dp,-1,sizeof dp);
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<n-i;j++)
            {
                if(pal(s,0,i-1,dp)&& pal(s,i,i+j-1,dp) && pal(s,i+j,n-1,dp))return 1;
            }
        }
        return 0;
    }
};