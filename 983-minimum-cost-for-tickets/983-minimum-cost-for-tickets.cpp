class Solution {
public:
    int dp[370],n;
    int solve(vector<int>& days, vector<int>& costs,int i)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        
        //if considering each day
        int a=costs[0]+solve(days,costs,i+1);
        
        //if considering 7 day
        int k=i+1;
        for(;k<days.size();k++)if(days[k]>=days[i]+7)break;
        int b=costs[1]+solve(days,costs,k);
        
        //if considering 30days
        for(;k<days.size();k++)if(days[k]>=days[i]+30)break;
        int c=costs[2]+solve(days,costs,k);
        
        return dp[i]=min(a,min(b,c));

        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        n=days.size();
        return solve(days,costs,0);
    }
};