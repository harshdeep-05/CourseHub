class Solution {
public:
    int dp[101][101];
    int solve(string ring,string key,int r,int k)
    {
        int n=ring.size();
        if(k==key.size())
            return 0;
        
        if(dp[r][k]!=-1)return dp[r][k];
        //search clockwise
        int cnt=0,j=r;
        while(ring[j]!=key[k])
        {
            j++;
            if(j==n)j=0;
            cnt++;

        }
        dp[r][k]=cnt+solve(ring,key,j,k+1);
        //anticlockwise
        j=r;
        cnt=0;
        while(ring[j]!=key[k])
        {
            j--;
            if(j<0)j=n-1;
            cnt++;

        }
        dp[r][k]=min(dp[r][k],cnt+solve(ring,key,j,k+1));
        // cout<<rr<<" ";
        return dp[r][k];
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof dp);
        return key.size()+solve(ring,key,0,0);
    }
};