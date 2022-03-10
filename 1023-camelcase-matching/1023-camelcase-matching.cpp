class Solution {
public:
    bool solve(string a,string b)
    {
        int i=0;
        for(auto c:a)
        {
            if(c>='A' && c<='Z' && c!=b[i])return false;
            if(c==b[i])i++;
        }
        return i==b.size();
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n=queries.size(),i=0;
        vector<bool> ans(n);
        
        for(auto s:queries)
        {
            ans[i++]=solve(s,pattern);
        }
        return ans;
        
    }
};