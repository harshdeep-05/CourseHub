class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& v,vector<int> &nums,vector<bool> &vis)
    {
        if(v.size()==nums.size())
        {
            ans.push_back(v);
            return ;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if((i==0 || vis[i-1] || nums[i]!=nums[i-1]) && !vis[i])
            {
            v.push_back(nums[i]);
            vis[i]=1;
            solve(v,nums,vis);
            vis[i]=0;
            v.pop_back();
        }
        }
        return;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v;
        vector<bool> vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        solve(v,nums,vis);
        return ans;
    }
};