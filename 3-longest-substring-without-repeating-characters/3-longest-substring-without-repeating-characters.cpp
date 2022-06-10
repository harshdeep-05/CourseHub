class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),l=0,r=0;
        if(n==0)return 0;
        
        unordered_map<char,int> m;
        int ans=0,cur=0;
        while(r<n)
        {
            if(m.find(s[r])==m.end() || m[s[r]]==0)
            {
                m[s[r]]=1;
                r++;
            }
            else 
            {
                m[s[l]]=0;
                l++;
            }
            ans=max(ans,r-l);
                
        }
        return ans;
    }
};