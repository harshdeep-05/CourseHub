class Solution {
public:
    int solve(string s,int i,int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1)return s;
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            int l1=solve(s,i,i);
            int l2=solve(s,i,i+1);
            int len=max(l1,l2);
            if(len>end-start)
            {
                start=i-(len-1)/2;
                end=i+len/2;
            }
            
        }
        return s.substr(start,end-start+1);
    }
};