class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n==k)return "0";
        string ans="";
        for(int i=0;i<n;i++)
        {
            while(!ans.empty() && ans.back()>num[i] && k)
            {
                k--;
                ans.pop_back();
            }
            ans+=num[i];
        }
        while(!ans.empty() && ans.back() && k)
            {
                k--;
                ans.pop_back();
            }
        int i=0;
        while(ans.size()>1 && ans[i]=='0')i++;
        ans=ans.substr(i);
        if(ans=="")return "0";
        return ans;
    }
};