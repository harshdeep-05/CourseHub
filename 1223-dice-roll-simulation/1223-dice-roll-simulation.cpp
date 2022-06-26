class Solution {
    int dp[5000][7][16];
    int mod = 1e9 + 7;
    int solve(int count, int n, vector<int>& rm, int prevnum, int prevnumcount) {
        if (count == n)
            return 1;
        if (dp[count][prevnum][prevnumcount] != -1)
            return dp[count][prevnum][prevnumcount];
        int res = 0;
        for (int i = 0; i < 6; i++) {
            if (i != prevnum)
                res = (res + solve(count + 1, n, rm, i, 1)) % mod;
            else if (prevnumcount < rm[i])
                res = (res + solve(count + 1, n, rm, prevnum, prevnumcount + 1)) % mod;
        }
        return dp[count][prevnum][prevnumcount] = res;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, rollMax, 6, 0);
    }
};