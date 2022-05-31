class Solution {
public:
    bool isValid(string s) {
        int i=0,n=s.size();
        for(int j=0;j<n;j++)
        {
            s[i++]=s[j];
            if(i>=3 && s[i-1]=='c' && s[i-2]=='b' && s[i-3]=='a')i-=3;
        }
        return (i==0);
    
    }
};