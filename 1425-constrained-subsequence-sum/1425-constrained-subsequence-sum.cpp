class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> q;
        q.push({nums[0],0});
        // vector<int> dp(n,0);
        // dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            while(!q.empty() && i-q.top().second>k)q.pop();
            nums[i]=max(nums[i],q.top().first+nums[i]);
            q.push({nums[i],i});
        }
        return *max_element(nums.begin(),nums.end());
        // return q.top().first;
    }
};