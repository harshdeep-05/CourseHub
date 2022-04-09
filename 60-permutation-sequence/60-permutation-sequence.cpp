class Solution {
public:
    vector<int> fact;
    void solve(int n)
    {
        fact= vector<int> (n);
        fact[0]=1;
        if(n==1)return;
        fact[1]=1;
        for(int i=2;i<n;i++)
        {
            fact[i]=i*fact[i-1];
        }
        return;
    }
    string getPermutation(int n, int k) {
        solve(n);
        vector<int> num(n);
        for(int i=0;i<n;i++)num[i]=i+1;
        string ans="";
        
        int i,j;
        k--;n--;
        while(n>=0)
        {
            i=k/fact[n];
            j=k%fact[n];
            
            ans+='0'+num[i];
            num.erase(num.begin()+i);
            n--;
            k=j;
        }
        return ans;
    }
};