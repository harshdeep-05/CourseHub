class Solution {
public:
    string say(string &s)
    {
        string ans="";
        int cnt=0,i=0;
        while(i<s.size())
        {
            int j=i;
            cnt=0;
            while(s[j]==s[i])
            {
                j++;
                cnt++;
            }
            ans+=cnt+'0';
            ans+=s[i];
            i=j;
        }
        return ans;
    }
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++)
        {
            s=say(s);
        }
        return s;
    }
};