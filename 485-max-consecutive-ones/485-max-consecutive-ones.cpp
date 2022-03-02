class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),ans=0,cur=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                cur++;
            }
            else
            {
                ans=max(cur,ans);
                cur=0;
            }
        }
        return max(cur,ans);
    }
};