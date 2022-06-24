class Solution {
public:
    /*
    int dp[100001];
    int solve(vector<int> &stones,int i)
    {
        int n=stones.size();
        if(i==n-1)return stones[i];
        if(dp[i]!=INT_MIN)return dp[i];
        
        dp[i]=max(solve(stones,i+1),
                  stones[i]-solve(stones,i+1));
        return dp[i];
    }
    */
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        for(int i=1;i<n;i++)stones[i]+=stones[i-1];
        //memset(dp,INT_MIN,sizeof dp);
        //return solve(stones,0);
        int ans=stones.back();
        for(int i=n-2;i>0;i--)
        {
            ans=max(ans,stones[i]-ans);
        }
            return ans;
        
    }
};