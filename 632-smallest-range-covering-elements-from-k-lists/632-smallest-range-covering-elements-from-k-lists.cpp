class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        int k=0;
        for(auto vp:nums)
        {
            k++;
            for(auto i:vp)
            {
                v.push_back({i,k});
            }
        }
        sort(v.begin(),v.end());
        int l=0,r=0,n=v.size(),len=n;
        unordered_map<int,int> m;
        vector<int> ans(2);
        ans[0]=-1e5;
        ans[1]=1e5;
        while(r<n)
        {
            m[v[r].second]++;
            
            while(m.size()==k)
            {
                if(r-l+1<len || v[r].first-v[l].first<ans[1]-ans[0])
                {
                    ans[0]=v[l].first;
                    ans[1]=v[r].first;
                    len=r-l+1;
                }
                m[v[l].second]--;
                if(m[v[l].second]==0)
                {
                    m.erase(v[l].second);
                }
                l++;
            }  
            r++;
        }
        return ans;
    }
};