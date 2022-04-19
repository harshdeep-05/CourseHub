class Solution {
public:
    string removeOccurrences(string s, string part) {
        string a=s;
        int m=part.size(),j=0;
        for(int i=0;i<s.size();i++)
        {
            a[j++]=s[i];
            if(j>=m && a.substr(j-m,m)==part)j-=m;
        }
        return a.substr(0,j);
    }
};