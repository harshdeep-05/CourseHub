class Solution {
public:
    int dp[101][101];
    int len(string& s,int i,int j)
    {
        int cnt=0;
        while(i<j)
            cnt+=(s[i++]!=s[j--]);
        
        return cnt;
    }
    
    int solve(string s,int i,int k)
    {
        if(dp[i][k]!=-1)return dp[i][k];
        
        int n=s.size();
        if(k==0 && i==n) 
            return 0;
        
        if(k==0)return n;
        if(i==n)return n;
        
        int ans=n;
        for(int j=i;j<n;j++)
        {
            ans=min(ans,len(s,i,j)+solve(s,j+1,k-1));
        }
        return dp[i][k]=ans;
    }
    
    int palindromePartition(string s, int k) {
        int n=s.size();
        if(k==n)return 0;
        memset(dp,-1,sizeof dp);
        return solve(s,0,k);
    }
};