class Solution {
public:
    int next(int n)
    {
        int x=0;
        while(n)
        {
            int d=n%10;
            n/=10;
            x+=d*d;
        }
        return x;
    }
    bool isHappy(int n) {
        while(n!=1 && n!=4)n=next(n);
        
        return n==1;
    }
};