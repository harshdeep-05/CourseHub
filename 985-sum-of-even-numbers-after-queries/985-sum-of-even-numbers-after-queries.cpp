class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0,j=0;
        vector<int> ans(queries.size(),0);
        for(auto i:nums)
        {
            if(i%2==0)sum+=i;
        }
        for(auto v:queries)
        {
            int i=v[1],val=v[0];
            if(nums[i]%2)
            {
                nums[i]+=val;
                if(val%2)sum+=nums[i];
            }
            else
            {
                sum-=nums[i];
                nums[i]+=val;
                if(nums[i]%2==0)sum+=nums[i];
            }
            ans[j++]=sum;
        }
        return ans;
    }
};