class Solution {
public:
    int solve(vector<int>& nums,int k)
    {
        int n=nums.size();
        unordered_map<int,int> m;
        int l=0,r=0;
        int ans=0,diff_elem=k;
        
        while(r<n)
        {
            m[nums[r]]++;
            while(m.size()>k)
            {
                m[nums[l]]--;
                if(m[nums[l]]==0)m.erase(nums[l]);
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};