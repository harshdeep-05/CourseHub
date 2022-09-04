class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans(nums.size()-k+1);
        int n=nums.size();
        for(int i=0;i<k;i++)
        {
            m[-nums[i]]++;
        }
        ans[0]=-m.begin()->first;
        for(int i=k;i<n;i++)
        {
            m[-nums[i]]++;
            m[-nums[i-k]]--;
            if(m[-nums[i-k]]==0)
                m.erase(-nums[i-k]);
            ans[i-k+1]=-m.begin()->first;
        }
        return ans;
            
    }
};