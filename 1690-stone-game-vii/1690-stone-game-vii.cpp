class Solution {
public:
    // int dp[1001][1001][2];
    // int solve(vector<int> &s,int i,int j,int a,int b,int flag)
    // {
    //     if(i==j)
    //     {
    //         return (a-b);
    //     }
    //     if(dp[i][j][flag]!=-1)return dp[i][j][flag];
    //     if(flag)
    //     {
    //         flag=0;
    //         return dp[i][j][flag]=max(solve(s,i+1,j,a+s[j]-s[i],b,flag),solve(s,i,j-1,a+s[j-1],b,flag));
    //     }
    //     flag=1;
    //     return dp[i][j][flag]=min(solve(s,i+1,j,a,b+s[j]-s[i],flag),solve(s,i,j-1,a,b+s[j-1],flag));
    // }
    int dp[1001][1001];
    int solve(vector<int>& v,int i,int j,int sum)
    {
        if(i==j)
            return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int left=sum-v[i]-solve(v,i+1,j,sum-v[i]);
        int right=sum-v[j]-solve(v,i,j-1,sum-v[j]);
        
        return dp[i][j]=max(left,right);
    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size(),sum=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
        {
            // stones[i]+=stones[i-1];
            sum+=stones[i];
        }
        return solve(stones,0,n-1,sum);
    }
};