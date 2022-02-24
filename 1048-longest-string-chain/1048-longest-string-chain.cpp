class Solution {
public:
    static bool yes(string a,string b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),yes);
        map<string,int> m;
        int ans=0;
        for(auto word:words)
        {
            int mx=0,n=word.size();
            for(int i=0;i<n;i++)
            {
                string s=word.substr(0,i)+word.substr(i+1,n+1);
                mx=max(mx,m[s]+1);
            }
            m[word]=mx;
            ans=max(mx,ans);
        }
        return ans;
    }
};