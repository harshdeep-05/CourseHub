class Solution {
public:  
    
    void solve(string s,int i,int j,int &ans)
    {
        if(s.size()==0 || i>j)return;
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
            ans++;
        }
    }
    
    int countSubstrings(string s) {
        if(s.size()==0)return 0;
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            solve(s,i,i,ans);
            solve(s,i,i+1,ans);
        }
        return ans;
        
        
    }
};