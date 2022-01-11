class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        
        vector<vector<int>> ans(n+1);
        
        for(int i=0;i<n;i++)
        {
            ans[groupSizes[i]].push_back(i);
            if(ans[groupSizes[i]].size()==groupSizes[i]){
                ans.push_back({});
                swap(ans.back(),ans[groupSizes[i]]);
            }
        }
        vector<vector<int>> res;
        for(auto i:ans)
        {
            if(i.size())res.push_back(i);
        }
        
        return res;
    }
};