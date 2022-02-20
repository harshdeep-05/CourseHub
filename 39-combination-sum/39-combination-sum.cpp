class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &cur,int i)
    {
        if(target==0)
        {
            ans.push_back(cur);
            return ;
        }
        if(target<0 || i==candidates.size())return;
        
        solve(candidates,target,ans,cur,i+1);
        
        cur.push_back(candidates[i]);
        solve(candidates,target-candidates[i],ans,cur,i);
        cur.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(candidates,target,ans,cur,0);
        return ans;
    }
};