class Solution {
public:
    const int mod=1e9+7;
    long long solve(int n)
    {
        if(n==1)
            return 1;
        
        int x=log2(n)+1;
        long long add=solve(n-1)*pow(2,x);
        add%=mod;
        return (add+n)%mod;
    }
    int concatenatedBinary(int n) {
        return solve(n)%mod;
    }
};