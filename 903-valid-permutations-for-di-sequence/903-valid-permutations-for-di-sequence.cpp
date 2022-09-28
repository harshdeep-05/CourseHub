class Solution {
public:
    int dp[202][202];
    const int mod=1e9+7;
    int solve(string &s,int i,int &prev,vector<int> &vis)
    {
        if(i==s.size())
            return 1;
        if(dp[i][prev]!=-1)return dp[i][prev];
        int ans=0;
        if(s[i]=='D')
        {
            for(int j=prev-1;j>=0;j--)
            {
                if(vis[j])continue;
                vis[j]=1;
                ans=(ans+solve(s,i+1,j,vis))%mod;
                vis[j]=0;
            }
        }
        else 
        {
            for(int j=prev+1;j<=s.size();j++)
            {
                if(vis[j])continue;
                vis[j]=1;
                ans=(ans+solve(s,i+1,j,vis))%mod;
                vis[j]=0;
            }
        }
        return dp[i][prev]=ans%mod;
    }
    int numPermsDISequence(string s) {
        memset(dp,-1,sizeof dp);
        int ans=0;
        vector<int> vis(s.size()+1,0);
        for(int i=0;i<=s.size();i++)
        {
            vis[i]=1;
            ans=(ans+solve(s,0,i,vis))%mod;
            vis[i]=0;
        }
        return ans%mod;
    }
};