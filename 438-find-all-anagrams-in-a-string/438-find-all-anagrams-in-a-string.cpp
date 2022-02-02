class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.size()<p.size())return v;
        
        vector<int> f(26,0),window(26,0);
        for(int i=0;i<p.size();i++)
        {
            f[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        if(f==window)v.push_back(0);
        for(int i=p.size();i<s.size();i++)
        {
            window[s[i-p.size()]-'a']--;
            window[s[i]-'a']++;
            if(f==window)v.push_back(i-p.size()+1);
        }
        return v;
    }
};