class Solution {
public:
    
    /*int ans=INT_MIN;
    int solve(vector<int> &nums,int idx,int &prod)
    {
        if(idx==nums.size())return 0;
        
        if(nums[idx]==0)
        {
            ans=max(ans,prod);
            prod=1;
            return solve(nums,idx+1,prod);
        }
        else if(nums[idx]<0)
        {
            return ans=max({ans,solve(nums,idx+1,prod*nums[idx]),solve(nums,idx+1,1)});
        }
        else
        {
            prod*=nums[idx];
            solve(nums,idx+1,prod);
        }
    }*/
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod=1,ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            prod*=nums[i];
            ans=max(ans,prod);
            if(nums[i]==0)
            {
                prod=1;
            }
            
        }
        prod=1;
        for(int i=n-1;i>=0;i--)
        {
            prod*=nums[i];
            ans=max(ans,prod);
            if(nums[i]==0)
            {
                prod=1;
            }
            
        }
        return ans;
    }
};