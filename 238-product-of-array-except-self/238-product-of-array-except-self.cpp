class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int zeros=count(nums.begin(),nums.end(),0);
        if(zeros>1)return ans;
        int prod=1,idx=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)idx=i;
            else prod*=nums[i];
        }
        if(zeros==1)
        {
            ans[idx]=prod;
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=prod/nums[i];
        }
        return ans;
        
    }
};