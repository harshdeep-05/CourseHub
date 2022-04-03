class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &vis,vector<int> &cur,vector<int>& nums)
    {
        if(cur.size()==nums.size())
        {
            ans.push_back(cur);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(!vis[i])
            {
                cur.push_back(nums[i]);
                vis[i]++; //Marking the index as visited
                solve(vis,cur,nums);
                cur.pop_back();
                vis[i]--; //Reverting the index as non-visited again.
                
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size(),0);
        vector<int> cur;
        solve(vis,cur,nums);
        
        return ans;
    }
};