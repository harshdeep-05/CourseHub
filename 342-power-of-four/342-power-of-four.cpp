class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return 0;
        while(n>1)
        {
            // cout<<n<<" ";
            if(n%4)return 0;
            n/=4;
        }
        return 1;
    }
};