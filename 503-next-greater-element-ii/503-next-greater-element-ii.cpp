class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end()),n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==mx)ans[i]=-1;
            else 
            {
                int k=i;
                while(nums[i]>=nums[k])k=(k+1)%n;
                ans[i]=nums[k];
            }
        }
        return ans;
            
    }
};