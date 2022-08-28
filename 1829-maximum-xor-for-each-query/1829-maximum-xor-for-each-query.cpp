class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans(n);
        int k=pow(2,maximumBit)-1,x=0;
        // k=k/2-1;
        // cout<<k<<" ";
        for(int i=0;i<n;i++)
        {
            x=x^nums[i];
            ans[n-i-1]=(x^k);
        }
        return ans;
    }
};