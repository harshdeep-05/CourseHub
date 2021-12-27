class Solution {
public:
    int findComplement(int num) {
        unsigned x=~0;
        while(x & num)x=x<<1;
        return ~num^x;
            
    }
};