class Solution {
public:
    int count(int n)
    {
        int c=0;
        while(n)
        {
            c+=n%2;
            n/=2;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
        {
            ans[i]=count(i);
        }
        return ans;
    }
};