class Solution {
public:
    bool check(int n)
    {
        int num=n;
        while(n)
        {
            int d=n%10;
            if(d==0 || num%d)return 0;
            n/=10;
        }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int n=left;n<=right;n++)
        {
            if(check(n))ans.push_back(n);
        }
        return ans;
    }
};