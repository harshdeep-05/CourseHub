class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26,0);
        int mx=0;
        for(auto c:s)
        {
            f[c-'a']++;
            if(f[c-'a']>f[mx])mx=c-'a';
        }
        if(f[mx]>(s.size()+1)/2)return "";
        string ans(s.size(),'.');
        int i=0;
        while(f[mx])
        {
            ans[i]=mx+'a';
            f[mx]--;
            i+=2;
        }
        for(int j=0;j<26;j++)
        {
            while(f[j])
            {
                if(i>=s.size())i=1;
                f[j]--;
                ans[i]=j+'a';
                i+=2;
            }
        }
        return ans;
    }
};