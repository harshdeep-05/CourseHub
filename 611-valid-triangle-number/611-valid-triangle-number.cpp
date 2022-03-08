class Solution {
public:
    bool valid(int a,int b,int c)
    {
        return (a+b>c);
    }
    int triangleNumber(vector<int>& nums) {
        int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=1,k=2;
        for(int i=n-1;i>=0;i--)
        {
            int l=0,r=i-1;
            
            while(l<r)
            {
                if(nums[l]+nums[r]<=nums[i])l++;
                else ans+=(r-l),r--;
            }
        }
        return ans;
    }
};