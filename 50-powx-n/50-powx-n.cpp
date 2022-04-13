class Solution {
public:
    double myPow(double x, int n) {
        if(x==1.0 || n==0)return 1.0;
        if (x == -1) {
            if (n % 2 == 0) return 1;
            else return -1;
        }
        if (n == INT_MIN) return 0;
        if(n<0)
        {
            x=1.0/x;
            n=-n;
        }
        double ans=1;
        while(n)
        {
            if(n&1)ans*=x;
            x*=x;
            n/=2;
        }
        return ans;
    }
};