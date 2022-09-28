class Solution {
public:
    int ans=INT_MAX;
    void solve(int i,int k,vector<int> &cookies,vector<int>& v)
    {
        if(i==cookies.size())
        {
            int mx=0;
            for(auto x:v)mx=max(x,mx);
            ans=min(ans,mx);
            return;
        }
        
        for(int j=0;j<k;j++)
        {
            v[j]+=cookies[i];
            solve(i+1,k,cookies,v);
            v[j]-=cookies[i];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k,0);
        solve(0,k,cookies,v);
        return ans;
    }
};