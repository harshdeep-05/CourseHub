class Solution {
public:
    vector<vector<string>> ans;
    bool istrue(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])return 0;
        }
        return 1;
    }
    
    void solve(string s,int i,vector<string> &cur)
    {
        if(i==s.size()){
            ans.push_back(cur);
            return;
        }
        for(int j=i;j<s.size();j++)
        {
            if(istrue(s,i,j))
            {
                cur.push_back(s.substr(i,j-i+1));
                solve(s,j+1,cur);
                cur.pop_back();
            }
        }
        return ;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        solve(s,0,cur);
        return ans;
    }
};