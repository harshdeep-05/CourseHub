class Solution {
public:
    void solve(string s,int i,int j,int &ans)
    {
        int cnt=0;
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
            cnt++;
        }
        ans+=cnt;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            solve(s,i,i,ans);
            solve(s,i,i+1,ans);
        }
        return ans;
    }
};