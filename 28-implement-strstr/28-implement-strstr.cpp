class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(n<m)return -1;
        for(int i=0;i<=n-m;i++)
        {
            int flag=1;
            for(int j=0;j<m;j++)
            {
                if(i+j<n && haystack[i+j]!=needle[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)return i;
        }
        return -1;
    }
};