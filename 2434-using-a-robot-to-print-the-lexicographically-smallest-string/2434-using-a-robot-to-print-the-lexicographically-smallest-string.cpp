class Solution {
public:
    int find(vector<int> &f)
    {
        for(int i=0;i<26;i++)
        {
            if(f[i])return i;
        }
        return 0;
    }
    string robotWithString(string s) {
        vector<int> f(26,0);
        for(auto c:s)f[c-'a']++;
        
        string ans="",t="";
        for(int i=0;i<s.size();i++)
        {
            t+=s[i];
            f[s[i]-'a']--;
            char c='a'+find(f); 
            while(!t.empty() && t.back()<=c)
            {
                ans+=t.back();
                t.pop_back();
            }
        }
        reverse(t.begin(),t.end());
        ans+=t;
        return ans;
    }
};