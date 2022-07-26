class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        
        int cur_sum=0,max_till_here=INT_MIN;
        for(int j=0;j<n;j++)
        {
            cur_sum+=nums[j];
            max_till_here=max(cur_sum,max_till_here);
            if(cur_sum<0)cur_sum=0;
        }
        int ans1=max_till_here,total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum+=nums[i];
            nums[i]*=-1;
        }
        cur_sum=0,max_till_here=INT_MIN;
        for(int j=0;j<n;j++)
        {
            cur_sum+=nums[j];
            max_till_here=max(cur_sum,max_till_here);
            if(cur_sum<0)cur_sum=0;
        }
        int ans2=max_till_here;
        if(ans2+total_sum==0)return ans1;
        return max(ans1,ans2+total_sum);
    }
};