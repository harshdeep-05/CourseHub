class Solution {
public:
    vector<vector<int> > ans;
    void solve(vector<int >&nums,int i,vector<int> &cur)
    {
        if(i==nums.size())return;
        
        for(int j=i;j<nums.size();j++)
        {
            cur.push_back(nums[j]);
            solve(nums,j+1,cur);
            ans.push_back(cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        ans.push_back(cur);
        solve(nums,0,cur);
        return ans;
    }
};