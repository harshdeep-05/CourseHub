class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26,0);
        for(auto c:s)f[c-'a']++;
        //vector<pair<int,char>> v;
        int ans=0;
        unordered_set<int> set;
        for(int i=0;i<26;i++)
        {
            while(f[i] && set.find(f[i])!=set.end())
            {
                f[i]--;
                ans++;
            }
            set.insert(f[i]);
        }
        
        return ans;
    }
};