class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k&1)==0)return -1;
        
        int n=1,len=1;
        for(int i=1;i<=k;i++)
        {
            if(n%k==0)return len;
            n=(n*10+1)%k;
            len++;
        }
        return -1;
    }
};