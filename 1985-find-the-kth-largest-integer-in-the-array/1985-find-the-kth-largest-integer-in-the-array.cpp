class Solution {
public:
    static bool comp(string a,string b)
    {
        if(a.size()==b.size())return a<b;
        return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        //for(auto i:nums)cout<<i<<" ";
        //cout<<"\n";
        return nums[nums.size()-k];
    }
};