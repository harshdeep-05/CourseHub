class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> v;
        int n=corridor.size();
        const int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='S')v.push_back(i);
        }
        if(v.size()==0 || v.size()%2)return 0;
        
        long long ans=1;
        for(int i=2;i<v.size();i+=2)
        {
            ans=(ans*(v[i]-v[i-1]))%mod;
        }
        return ans;
    }
};