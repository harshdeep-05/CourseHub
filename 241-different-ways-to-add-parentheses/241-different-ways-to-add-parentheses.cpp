class Solution {
public:
    vector<int> solve(string s,unordered_map<string,vector<int>> &m)
    {
        vector<int> ans;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+'|| s[i]=='-'|| s[i]=='*')
            {
                vector<int> l,r;
                string sub=s.substr(0,i);
                if(m.find(sub)!=m.end())
                {
                    l=m[sub];
                }
                else l=solve(sub,m);
                
                string sub2=s.substr(i+1);
                if(m.find(sub2)!=m.end())
                {
                    r=m[sub2];
                }
                else r=solve(sub2,m);
                
                for(auto x:l)
                {
                    for(auto y:r)
                    {
                        if(s[i]=='+')ans.push_back(x+y);
                        else if(s[i]=='-')ans.push_back(x-y);
                        else ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.empty()){
            int x=0;
            for(auto i:s)x=x*10+i-'0';
            ans.push_back(x);
        }
        m[s]=ans;
        return ans;
    }
    vector<int> diffWaysToCompute(string s) {
        unordered_map<string,vector<int>> m;
        return solve(s,m);
    }
};