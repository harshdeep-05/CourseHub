class Solution {
public:
    int numSub(string s) {
        long long ans=0, n=s.size(),i=0;
        int mod=1e9+7;
        while(i<n)
        {
            int j=i;
            while(s[j]=='1' && j<n)j++;
            if(j-i){
                long long l=(j-i)*(j-i+1)/2;
                ans=(ans+l%mod)%mod;
            }
            i=j+1;
        }
        return ans;
    }
};