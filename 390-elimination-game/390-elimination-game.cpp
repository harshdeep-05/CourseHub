class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return n;
        if(n%2)n--;
        int k=lastRemaining(n/2);
        return n+2-2*k;
    }
};