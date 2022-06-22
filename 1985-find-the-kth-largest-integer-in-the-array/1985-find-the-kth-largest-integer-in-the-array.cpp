class Solution {
public:
    static bool comp(string a,string b)
    {
        int i=0;
        if(a.size()!=b.size())return a.size()<b.size();
        while(i<a.size() && a[i]==b[i])
        {
            i++;
        }
        if(i==a.size())return 0;
        return a[i]<b[i];
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comp);
        for(auto i:nums)cout<<i<<" ";
        cout<<"\n";
        return nums[nums.size()-k];
    }
};