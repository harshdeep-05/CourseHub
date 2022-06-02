class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int x=nums.size()-k;
        for(int i=0;i<nums.size();i++)
        {
            while(!ans.empty() && ans.back()>nums[i] && x)
            {
                ans.pop_back();
                x--;
            }
            ans.push_back(nums[i]);
        }
        return vector<int>(ans.begin(),ans.begin()+k);
    }
};