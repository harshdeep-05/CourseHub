class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> pre(n+1,0);
        for(auto v:shifts)
        {
            if(v[2]==1)
            {
                pre[v[0]]++;
                pre[v[1]+1]--;
            }
            else
            {
                pre[v[0]]--;
                pre[v[1]+1]++;
            }
        }
        for(int i=1;i<n;i++)
        {
            pre[i]+=pre[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            // cout<<pre[i]<<" ";
            int x=s[i]-'a';
            x=(x+pre[i])%26;
            // cout<<x<<" ";
            if(x<0)x=26+x;
            s[i]='a'+x%26;
        }
        return s;
    }
};