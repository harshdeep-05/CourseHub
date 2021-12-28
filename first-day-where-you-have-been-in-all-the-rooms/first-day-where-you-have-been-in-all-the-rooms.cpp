class Solution {
public:
    int mod=1e9+7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n=nextVisit.size();
        vector<long> dp(n,0);
        for(int i=1;i<n;i++)
        {
            dp[i]=(2*dp[i-1]-dp[nextVisit[i-1]]+mod+2)%mod;
        }
        return dp[n-1];
    }
};