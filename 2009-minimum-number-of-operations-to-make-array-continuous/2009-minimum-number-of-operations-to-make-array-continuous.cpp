class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            while(i<n-1 && nums[i]==nums[i+1])i++;
                v.push_back(nums[i]);
        }
        for(int i=0;i<v.size();i++)
        {
            int mx=v[i]+n-1;
            int j=upper_bound(v.begin(),v.end(),mx)-v.begin();
            ans=max(ans,j-i);
        }
        return n-ans;
    }
};