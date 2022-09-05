class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> m;
        int l=0,r=0,mx=0;
        int ans=0;
        for(auto c:s)
        {
            r++;
            m[c]++;
            mx=max(mx,m[c]);
            if(r-l-mx>k)
            {
                m[s[l]]--;
                l++;
            }
            else ans=max(ans,r-l);
            
        }
        return ans;
    }
};