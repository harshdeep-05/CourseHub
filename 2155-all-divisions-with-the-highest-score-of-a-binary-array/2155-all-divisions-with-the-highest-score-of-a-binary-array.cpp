class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int right=0,n=nums.size(),mx=0,left=0;
        for(auto i:nums)right+=i;
        
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            if(left+right==mx)ans.push_back(i);
            else if(left+right>mx)
            {
                mx=left+right;
                ans.clear();
                ans.push_back(i);
            }
            
            if(i!=n)
            {
                if(nums[i]==1)right--;
                else left++;
            }
        }
        return ans;
    }
};