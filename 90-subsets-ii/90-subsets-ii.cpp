class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int> &nums,int i,vector<int> &cur)
    {
        if(i==nums.size())return;
        
        for(int j=i;j<nums.size();j++)
        {
            cur.push_back(nums[j]);
            solve(nums,j+1,cur);
            s.insert(cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur;
        vector<vector<int>> ans;
        ans.push_back(cur);
        solve(nums,0,cur);
        for(auto v:s)ans.push_back(v);
        return ans;
    }
};