class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int c=0;
        string p="";
        unordered_map<char,int> m;
        for(auto i:pattern)
            {
                if(m.find(i)==m.end())m[i]=c++;
                p+='0'+m[i];
            }
        for(auto s:words)
        {
            int c=0;
            string x="";
            unordered_map<char,int> m;
            for(auto i:s)
            {
                if(m.find(i)==m.end())m[i]=c++;
                x+='0'+m[i];
            }
            
            if(x==p)ans.push_back(s);
        }
        return ans;
    }
};