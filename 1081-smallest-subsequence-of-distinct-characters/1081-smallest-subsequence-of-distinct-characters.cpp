class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26,0);
        unordered_map<char,int> m;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]=i;
            //f[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]-'a'])continue;
            while(!ans.empty() && ans.back()>s[i] && m[ans.back()]>i)
            {
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans+=s[i];
            vis[s[i]-'a']=true;
        }
        return ans;
    }
};