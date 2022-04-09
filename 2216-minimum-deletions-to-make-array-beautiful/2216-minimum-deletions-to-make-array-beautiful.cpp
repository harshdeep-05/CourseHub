class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if((i-ans)%2)continue;
            if(nums[i]==nums[i+1])
            {
                ans++;
            }
        }
        if((n-ans)%2)ans++;
        return ans;
    }
};