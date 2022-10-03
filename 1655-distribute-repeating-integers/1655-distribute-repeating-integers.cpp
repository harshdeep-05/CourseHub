class Solution {
public:
    bool ans;
    void solve(vector<int>& v,int i,vector<int> &c)
    {
        if(i==v.size() || ans)
        {
            ans=1;
            return ;
        }
        // bool ans
        for(int j=0;j<c.size();j++)
        {
            if(c[j]>=v[i])
            {
                c[j]-=v[i];
                solve(v,i+1,c);
                c[j]+=v[i];
            }
        }
        return ;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> m;
        for(auto i:nums)m[i]++;
        vector<int> c;
        for(auto i:m)
        {
            c.push_back(i.second);
        }
        sort(quantity.rbegin(),quantity.rend());
        solve(quantity,0,c);
        return ans;
    }
};