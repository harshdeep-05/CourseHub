class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm=(p*q)/(__gcd(p,q));
        if((lcm/q)%2==0)return 2;
        else return (lcm/p)%2;
        
    }
};