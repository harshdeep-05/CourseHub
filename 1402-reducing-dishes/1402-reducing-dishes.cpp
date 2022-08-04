class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& v,int idx,int time)
    {
        if(idx==v.size())return 0;
        if(dp[idx][time]!=-1)return dp[idx][time];
        int taken=solve(v,idx+1,time+1)+v[idx]*time;
        int not_taken=solve(v,idx+1,time);
        return dp[idx][time]=max(taken,not_taken);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof dp);
        return solve(satisfaction,0,1);
    }
};