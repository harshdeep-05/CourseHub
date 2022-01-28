class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int> &nums,int i,vector<int> v)
    {
        if(i==nums.size()){
            if(v.size()>1){
                ans.insert(v);
            }
            return;
        }
        
        solve(nums,i+1,v);
        if(v.size()==0 || nums[i]>=v.back())
        {
            v.push_back(nums[i]);
            solve(nums,i+1,v);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,0,{});
        vector<vector<int>> a;
        for(auto i:ans)a.push_back(i);
        return a;
    }
};