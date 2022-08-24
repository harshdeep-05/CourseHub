class Solution {
public:
    bool solve(int n,int i,vector<int>&v)
    {
        if(n==0)return 1;
        if(i<0 || n<0)return 0;
        return (solve(n-v[i],i-1,v) or solve(n,i-1,v));
    }
    bool checkPowersOfThree(int n) {
        vector<int> num;
        int i=1;
        while(i<=n)
        {
            num.push_back(i);
            i*=3;
        }
        return solve(n,num.size()-1,num);
    }
};