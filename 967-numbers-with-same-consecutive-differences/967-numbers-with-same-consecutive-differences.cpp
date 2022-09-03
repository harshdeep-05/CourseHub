class Solution {
public:
    void solve(int n,int k,vector<int> &ans,int num)
    {
        if(n==0)
        {
            ans.push_back(num);
            return;
        }
        int d=num%10;
        if(d+k<=9)
        {
            num=num*10+(d+k);
            solve(n-1,k,ans,num);
            num/=10;
        }
        if(d-k>=0 && k!=0)
        {
            num=num*10+(d-k);
            solve(n-1,k,ans,num);
        }
        return;
    }
        
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            solve(n-1,k,ans,i);
        }
        return ans;
    }
};