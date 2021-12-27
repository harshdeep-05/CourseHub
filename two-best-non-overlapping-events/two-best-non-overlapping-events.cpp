class Solution {
public:
    int n=1e5;
    
    int solve(int i,int no_events,vector<vector<int>>& events,vector<vector<int>> &dp)
    {
        if(i == events.size() || no_events == 2)return 0;
        if(dp[i][no_events]!=-1)return dp[i][no_events];
        
        vector<int> temp = {events[i][1] , INT_MAX , INT_MAX};
        int j = upper_bound(events.begin() , events.end() , temp) - events.begin(); 
        int val1 = events[i][2] + solve(j , no_events+1 , events,dp);
        
        int val2 = solve(i+1 , no_events , events,dp);
        
        return dp[i][no_events]=max(val1 , val2);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        sort(events.begin(),events.end());
        return solve(0,0,events,dp);
    }
};