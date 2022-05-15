class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        vector<int> f1(26,0),f2(26,0);
        for(auto c:s)f1[c-'a']++;
        for(auto c:t)f2[c-'a']++;
        for(int i=0;i<26;i++)
        {
            ans+=abs(f1[i]-f2[i]);
        }
        return ans/2;
    }
};