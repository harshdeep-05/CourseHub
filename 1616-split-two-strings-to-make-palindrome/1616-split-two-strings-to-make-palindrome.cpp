class Solution {
public:
    bool pal(string &s,int i,int j)
    {
        // int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;j--;
            }
            else return 0;
        }
        return 1;
    }
    
    bool check(string a,string b)
    {
        int n=a.size();
        int i=0,j=n-1;
        while(j>=0 && a[i]==b[j])
        {
            i++;
            j--;
        }
        if(i==j)return 1;
        
        return (pal(b,i,j)|| pal(a,i,j));
    }
    bool checkPalindromeFormation(string a, string b) {
        int n=a.size();
        if(pal(a,0,n-1) || pal(b,0,n-1))
            return 1;
        
        if(check(a,b) || check(b,a))
            return 1;
        
        return 0;
    }
};