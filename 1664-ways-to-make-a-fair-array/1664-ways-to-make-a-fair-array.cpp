class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size(),sum=nums[0];
        vector<int> odd(n+1,0),even(n+1,0);
        even[0]=nums[0];
        for(int i=n-1;i>=0;i--)
        {
            if(i%2){
                odd[i]=nums[i]+odd[i+1];
                even[i]=even[i+1];
            }
            else
            {
                even[i]=nums[i]+even[i+1];
                odd[i]=odd[i+1];
            }
            sum+=nums[i];
        }
        int ans=0,e=0,o=0;
        for(int i=0;i<n;i++)
        {
            if(e+odd[i+1] == o+even[i+1])ans++;
            if(i%2)o+=nums[i];
            else e+=nums[i];
        }
        return ans;
    }
};