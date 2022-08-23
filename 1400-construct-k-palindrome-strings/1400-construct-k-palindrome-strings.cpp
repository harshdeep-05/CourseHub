class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return 0;
        if(s.size()==k)return 1;
        unordered_map<char,int> m;
        for(auto c:s)m[c]++;
        int odd=0,even=0;
        for(auto i:m)
        {
            if(i.second%2)odd++;
            else even++;
        }
        if(odd>k)return 0;
        return 1;
    }
};