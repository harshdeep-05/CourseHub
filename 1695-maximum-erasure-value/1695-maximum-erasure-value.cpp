class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),start=0,end=0;
        int ans=0,cur=0;
        
        vector<int> freq(10001,0);
        while(end<n)
        {
            if(freq[nums[end]]==1)
            {
                freq[nums[start]]=0;
                cur-=nums[start];
                start++;
                
            }
            else 
            {
                freq[nums[end]]=1;
                cur+=nums[end];
                end++;   
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};