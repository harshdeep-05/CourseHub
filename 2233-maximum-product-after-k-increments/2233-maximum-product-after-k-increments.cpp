class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto i:nums)q.push(-i);
        while(k--)
        {
            auto top=-q.top();
            q.pop();
            top++;
            q.push(-top);
        }
        long long ans=1,mod=1e9+7;
        while(!q.empty())
        {
            int top=-q.top();
            q.pop();
            ans=((ans%mod)*top)%mod;
            
        }
        return ans%mod;
    }
};