class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n<2)return s;
        int prime=29,mod=1e9+7;
        long long int p=prime;
        long long int shash=s[0]-'a'+1,rhash=s[0]-'a'+1;
        
        int index=0;
        for(int i=1;i<n;i++)
        {
            int c=s[i]-'a'+1;
            shash=shash+c*p;
            shash%=mod;
            rhash=rhash*prime+c;
            rhash%=mod;
            
            p=(p*prime)%mod;
            if(shash==rhash)
            {
                index=i;
            }
        }
        
        string rev=s.substr(index+1);
        reverse(rev.begin(),rev.end());
        return rev+s;
    }
};