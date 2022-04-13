class Solution {
public:
    int k=1337;
    int solve(int a,int x)
    {
        a%=k;
        int ans=1;
        for(int i=0;i<x;i++)
        {
            ans=(a*ans)%k;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if(b.size()==0)return 1;
        int x=b.back();
        b.pop_back();
        
        return solve(superPow(a,b),10)*solve(a,x)%k;
        
    }
};