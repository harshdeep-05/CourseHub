class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y,ans=0;
        while(n)
        {
            ans+=n%2;
            n/=2;
        }
        return ans;
    }
};