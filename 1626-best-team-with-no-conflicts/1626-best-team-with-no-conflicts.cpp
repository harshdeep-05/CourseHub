class Solution {
public:
    int dp[1001][1001];
    int solve(vector<pair<int,int>> &v,int i,int age)
    {
        if(i==v.size())return 0;
        if(dp[i][age]!=-1)return dp[i][age];
        if(age<=v[i].second)
            return dp[i][age]=max(solve(v,i+1,age),solve(v,i+1,v[i].second)+v[i].first);
        return dp[i][age]=solve(v,i+1,age);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={scores[i],ages[i]};
        }
        sort(v.begin(),v.end());
        
        memset(dp,-1,sizeof dp);
        return solve(v,0,0);
    }
};