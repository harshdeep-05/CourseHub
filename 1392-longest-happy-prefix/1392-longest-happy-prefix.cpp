class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        long long prime=31,p=1;
        long long pre=0,suf=0;
        int mod=1e9+7,k=0;
        for(int i=0;i<n-1;i++)
        {
            pre=(pre*31+(s[i]-'a'+1))%mod;
            suf=(suf+(s[n-i-1]-'a'+1)*p)%mod;
            p=(p*prime)%mod;
            
            if(pre==suf)k=i+1;
        }
        return s.substr(0,k);
    }
};