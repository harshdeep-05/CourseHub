class Solution {
public:
    int set_bits(int num)
    {
        int ans=0;
        while(num)
        {
            ans+=num%2;
            num/=2;
        }
        return ans;
    }
        
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> s;
        for(auto i:nums)s.insert(i);
        vector<int> v;
        for(auto i:s)
        {
            v.push_back(set_bits(i));
            //cout<<v.back()<<" ";
        }
        sort(begin(v),end(v));
        long long ans=0,n=v.size();
        for(int i=0;i<v.size();i++)
        {
            auto it=lower_bound(begin(v),end(v),k-v[i]);
            ans+=v.end()-it;
        }
        return ans;
    }
};