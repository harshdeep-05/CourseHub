class Solution {
public:
    int dp[501][501];
    /*
    int solve(vector<int>& a, vector<int>& b,int i,int j)
    {
        if(i==a.size() || j==b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j])return dp[i][j]=solve(a,b,i+1,j+1)+1;
        return dp[i][j]=max(solve(a,b,i+1,j),solve(a,b,i,j+1));
    }*/
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i*j==0)dp[i][j]=0;
            else
            {
                if(nums1[i-1]==nums2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            }
            
        }
        
        return dp[n][m];
        //return solve(nums1,nums2,0,0);
    }
};