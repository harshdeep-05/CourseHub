class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        vector<long long> ans(n),pre(n,0),suf(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]].push_back(i);
        }
        
        for(auto &p:m){
            auto vec=p.second;
            for(int i=1;i<vec.size();i++)
                pre[vec[i]]=  pre[vec[i-1]]+  i*(long)(vec[i]-vec[i-1]);
        }
        for(auto &p:m){
            auto vec=p.second;
            for(int i=vec.size()-2;i>=0;i--)
                suf[vec[i]]=  suf[vec[i+1]] + long(vec.size()-1-i) * (long)(vec[i+1]-vec[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            ans[i]=pre[i]+suf[i];
        }
        return ans;
        
    }
};