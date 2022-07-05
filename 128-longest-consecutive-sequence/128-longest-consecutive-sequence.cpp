class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)return 0;
        int cur=1,ans=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(nums[i]==nums[i-1]+1)
            {
                cur++;
            }
            else
            {
                ans=max(cur,ans);
                cur=1;
            }
            }
        }
        ans=max(ans,cur);
        return ans;
    }
};