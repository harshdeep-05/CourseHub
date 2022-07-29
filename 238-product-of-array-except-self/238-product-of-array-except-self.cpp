class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        /*
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
        */
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=suffix;
            suffix*=nums[i];
        }
        
        return ans;
        
    }
};