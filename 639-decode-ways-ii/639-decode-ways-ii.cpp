class Solution {
public:
    int mod=1e9+7;
    /*
    long long dp[100001];
    int solve(string s,int i)
    {
        if(i<0)return 1;
        
        if(dp[i]!=-1)return dp[i];
        if(s[i]=='*')
        {
            dp[i]=9*solve(s,i-1)%mod;
            
            if(i-1>=0 && s[i-1]=='1')dp[i]=(dp[i]+9*solve(s,i-2)%mod)%mod;
            else if(i-1>=0 && s[i-1]=='2')dp[i]=(dp[i]+6*solve(s,i-2)%mod)%mod;
            else if(i-1>=0 && s[i-1]=='*')dp[i]=(dp[i]+15*solve(s,i-2)%mod)%mod;
            
            return dp[i];
        }
        dp[i]=s[i]!='0' ? solve(s,i-1)%mod : 0;
        
        if(i-1>=0 && s[i-1]=='1')dp[i]=(dp[i]+solve(s,i-2)%mod)%mod;
        else if(i-1>=0 && s[i-1]=='2' && (s[i]<='6'))dp[i]=(dp[i]+solve(s,i-2)%mod)%mod;
        else if(i-1>=0 && s[i-1]=='*'){
            if(s[i]<='6')
                dp[i]=(dp[i]+2*solve(s,i-2)%mod)%mod;
            else 
                dp[i]=(dp[i]+solve(s,i-2)%mod)%mod;
        }
        return dp[i];
    }
    */
    int numDecodings(string s) {
        //memset(dp,-1,sizeof dp);
        //return solve(s,s.size()-1);
        
        int n=s.size();
        long long dp[n+1];
        dp[0]=1;
        dp[1]=(s[0]=='*')?9 : (s[0]=='0')?0:1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='*')
            {
                dp[i+1]=9*dp[i]%mod;
                
                if(s[i-1]=='1')
                {
                    dp[i+1]=(dp[i+1]+9*dp[i-1]%mod)%mod;
                }
                else if(s[i-1]=='2')dp[i+1]=(dp[i+1]+6*dp[i-1]%mod)%mod;
                else if(s[i-1]=='*')dp[i+1]=(dp[i+1]+15*dp[i-1]%mod)%mod;
            }
            else
            {
                dp[i+1]=s[i]!='0' ? dp[i]%mod : 0;
        
                if(s[i-1]=='1')dp[i+1]=(dp[i+1]+dp[i-1]%mod)%mod;
                else if(s[i-1]=='2' && (s[i]<='6'))dp[i+1]=(dp[i+1]+dp[i-1]%mod)%mod;
                else if(s[i-1]=='*')
                {
                    if(s[i]<='6')
                        dp[i+1]=(dp[i+1]+2*dp[i-1]%mod)%mod;
                    else 
                        dp[i+1]=(dp[i+1]+dp[i-1]%mod)%mod;
                }
            }
        }
        return dp[n];
    }
};