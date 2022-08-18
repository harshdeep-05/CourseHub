class Solution {
public:
    int calc(int state, int n, int ns, vector<int>& dp, vector<int>& ar, vector<int>& br) {
        if(dp[state] != -1) return dp[state];
        if(state == 0) return 0;
        dp[state] = INT_MAX;
        for(int i = 0; i < n; i++) {
            if((state & (1 << i)) != 0) {
                dp[state] = min(dp[state], calc((state - (1 << i)), n, ns - 1, dp,ar,br) + (ar[ns - 1] ^ br[i]));
            }
        }
        return dp[state];
    }
    int minimumXORSum(vector<int>& ar, vector<int>& br) {
        int n=ar.size();
        vector<int> ans((1<<n), -1);
        return calc((1 << n) - 1, n, n, ans, ar, br);
    }
};