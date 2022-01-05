class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1,r=0,b=0;;
        
        for(auto i:nums)
        {
            if(i==0)r++;
            else if(i==2)b++;
        }
        while(r--)nums[i++]=0;
        while(b--)nums[j--]=2;
        while(i<=j)nums[i++]=1;
        
    }
};