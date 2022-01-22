class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x/2,ans;
        if(x<=1)return x;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(m==0)
            {
                return l+1;
            }
            if(m==x/m)return m;
            if(m<x/m)l=m+1,ans=m;
            else r=m-1;
        }
        return ans;
    }
};