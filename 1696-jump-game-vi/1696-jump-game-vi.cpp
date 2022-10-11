class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        // map<int,int> m;
        multiset<int> m;
        dp[0]=nums[0];
        m.insert(dp[0]);
        for(int i=1;i<n;i++)
        {
            if(i>k)m.erase(m.find(dp[i-k-1]));
            dp[i] = *rbegin(m) + nums[i];
            m.insert(dp[i]);
        }
        return dp[n-1];
    }
};