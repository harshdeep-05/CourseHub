class Solution {
public:
    static bool yes(string a,string b)
    {
        return (a.size()<b.size());
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),yes);
        unordered_map<string,int> m;
        int ans=0;
        for(auto s:words)
        {
            int n=s.size(),cur=0;
            for(int i=0;i<n;i++)
            {
                string temp=s.substr(0,i)+s.substr(i+1,n+1);
                cur=max(cur,m[temp]+1);
            }
            m[s]=cur;
            ans=max(ans,cur);
        }
        return ans;
    }
};