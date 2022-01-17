class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,int> m;
        map<string,int> mp;
        istringstream in(s);
        string a;
        int i=0;
        for(a; in>>a ;i++)
        {
            
            if(i==pattern.size() || mp[a]!=m[pattern[i]]){
                return false;
            }
            
            mp[a]=m[pattern[i]]=i+1;
        }
        return i==pattern.size();
    }
};