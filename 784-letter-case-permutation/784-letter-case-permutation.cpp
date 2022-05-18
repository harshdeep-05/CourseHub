class Solution {
public:
    vector<string> ans;
    void solve(string s,int i,string cur)
    {
        if(i==s.size())
        {
            ans.push_back(cur);
            return;
        }
        if(s[i]>='0' && s[i]<='9')
        {
            cur.push_back(s[i]);
            solve(s,i+1,cur);
        }
        else
        {
            string a=cur;
            a.push_back(tolower(s[i]));
            solve(s,i+1,a);
            
            string b=cur;
            b.push_back(toupper(s[i]));
            solve(s,i+1,b);
        }
    }
    vector<string> letterCasePermutation(string s) {
        ans.clear();
        solve(s,0,"");
        return ans;
        
    }
};