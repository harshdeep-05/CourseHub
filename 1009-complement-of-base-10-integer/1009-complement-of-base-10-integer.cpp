class Solution {
public:
    int bitwiseComplement(int n) {
        int i=0;
        while(i<=n)
        {
            i=i*2+1;
            if(i>=n)break;
        }
        return i-n;
    }
};