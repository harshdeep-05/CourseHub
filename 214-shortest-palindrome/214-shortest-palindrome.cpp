class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string a=s+'#'+rev;
        int m=a.size();
        vector<int> f(m,0);
        for(int i=1;i<m;i++)
        {
            int j=f[i-1];
            while(j>0 && a[i]!=a[j])j=f[j-1];
            
            if(a[i]==a[j])j++;
            f[i]=j;
        }
        return rev.substr(0,n-f[m-1])+s;
        
    }
};