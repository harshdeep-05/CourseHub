class Solution {
public:
    int countHomogenous(string s) {
        long long ans=0, n=s.size(),i=0,j;
        int mod=1e9+7;
        while(i<n)
        {
            j=i;
            while(s[j]==s[i] && j<n)j++;
            if(j-i){
                long long l=(j-i)*(j-i+1)/2;
                ans=(ans+l%mod)%mod;
            }
            i=j;
        }
        return ans;
        
    }
};