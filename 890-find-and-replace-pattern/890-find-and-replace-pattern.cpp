class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto s:words)
        {
            unordered_map<char,char> m,n;
            int flag=1;
            for(int i=0;i<s.size();i++)
            {
                
                if(m.find(pattern[i])==m.end() && n.find(s[i])==m.end())
                {
                    m[pattern[i]]=s[i];
                    n[s[i]]=pattern[i];
                }
                else
                {
                    if(m[pattern[i]]!=s[i] || n[s[i]]!=pattern[i])
                    {
                        flag=0;
                        break;
                    }
                }
                
            }
            if(flag)ans.push_back(s);
        }
        return ans;
    }
};