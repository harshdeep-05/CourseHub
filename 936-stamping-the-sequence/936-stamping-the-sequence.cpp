class Solution {
public:
    bool equal(string a,string b)
    {
        if(a.size()!=b.size())return 0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]=='?')continue;
            if(a[i]!=b[i])return 0;
        }
        return 1;
    }
    bool empty(string s)
    {
        for(auto c:s)if(c!='?')return 0;
        return 1;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int m=stamp.size(),n=target.size();
        vector<int> ans;
        bool match=1;
        while(match)
        {
            match=0;
            for(int i=0;i<n-m+1;i++)
            {
                string s=target.substr(i,m);
                if(empty(s))continue;
                if(equal(s,stamp))
                {
                    ans.push_back(i);
                    // cout<<i<<" ";
                    for(int j=0;j<m;j++)target[j+i]='?';
                    match=1;
                }
            }
        }
        if(!empty(target) || ans.size()>10*n)return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};