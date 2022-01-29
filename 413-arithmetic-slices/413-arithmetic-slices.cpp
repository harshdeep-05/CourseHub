class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        int d=nums[1]-nums[0],ans=0,j=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==d)j++;
            else
            {
                ans+=(j+1)*j/2;
                j=0;
                d=nums[i]-nums[i-1];
            }
        }
        ans+=(j+1)*j/2;
        return ans;
    }
};