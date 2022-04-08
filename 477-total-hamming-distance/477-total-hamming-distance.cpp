class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> bits(32, 0);
        for(auto i = 0; i <= 31; i++){
            for(auto j = 0; j < n; j++)
                bits[i]+= (nums[j]>>i) & 1;
            ans+=bits[i]*(n - bits[i]);
        }
        return ans;
    }
};