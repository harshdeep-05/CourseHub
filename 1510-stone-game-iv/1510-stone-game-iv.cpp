class Solution {
public:
    vector<int> dp;
    bool solve(int n)
    {
        if(dp[n]!=-1)
            return dp[n];
        
        for(int i=sqrt(n);i>=1;i--)
        {
            if(!solve(n-i*i))
            {
                return dp[n]=1;
            }
        }
        return dp[n]=0;
    }
    bool winnerSquareGame(int n) {
        dp=vector<int> (n+1,-1);
        dp[0]=0;
        return solve(n);
    }
};