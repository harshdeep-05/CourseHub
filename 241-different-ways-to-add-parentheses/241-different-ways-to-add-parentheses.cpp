class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+'|| s[i]=='-'|| s[i]=='*')
            {
                vector<int> l=diffWaysToCompute(s.substr(0,i));
                vector<int> r=diffWaysToCompute(s.substr(i+1));
                
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
        return ans;
    }
};