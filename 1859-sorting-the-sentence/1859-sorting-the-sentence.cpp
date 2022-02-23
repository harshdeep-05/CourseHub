class Solution {
public:
    string sortSentence(string s) {
        int n=0,i=0;
        for(auto i:s)
        {
            if(i>='0' && i<='9')n=max(i-'0',n);
        }
        vector<string> ans(n);
        while(i<s.size())
        {
            string cur="";
            while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                cur+=s[i++];
            }
            int j=s[i]-'0'-1;
            ans[j]=cur;
            i+=2;
        }
        string res="";
        for(auto i:ans)res+=i+' ';
        res.pop_back();
        return res;
        
    }
};