class Solution {
public:
    int ans=0;
    void solve(unordered_set<string> &set,string &s,int i,int cur)
    {
        if(i==s.size())
        {
            ans=max(ans,cur);
            return;
        }
        
        for(int j=i;j<s.size();j++)
        {
            string sub=s.substr(i,j-i+1);
            if(set.count(sub))continue;
            set.insert(sub);
            solve(set,s,j+1,cur+1);
            set.erase(sub);
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        solve(set,s,0,0);
        return ans;
    }
};