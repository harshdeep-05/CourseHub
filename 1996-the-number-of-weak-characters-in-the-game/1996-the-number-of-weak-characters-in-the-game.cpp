class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        int a=nums[n-1][0],b=nums[n-1][1],lmax=b;
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i][0]<nums[i+1][0])
            {
                b=max(lmax,b);
                lmax=max(lmax,nums[i][1]);
            }
            if(nums[i][0]<a && nums[i][1]<b )ans++;
        }
        return ans;
            
            
    }
};