class Solution {
public:
    bool isAnagram(string s, string t) {
        int f[26]={0};
        for(auto c:s)f[c-'a']++;
        for(auto c:t)f[c-'a']--;
        
        for(int i=0;i<26;i++)
        {
            if(f[i])return 0;
        }
        return 1;
    }
};