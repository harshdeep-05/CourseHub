class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>& tri,int r,int c)
    {
        if(dp[r][c]!=-1)return dp[r][c];
        if(r==tri.size() || c==tri[r].size())return 0;
        return dp[r][c]=min(solve(tri,r+1,c),solve(tri,r+1,c+1))+tri[r][c];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof dp);
        return solve(triangle,0,0);
    }
};