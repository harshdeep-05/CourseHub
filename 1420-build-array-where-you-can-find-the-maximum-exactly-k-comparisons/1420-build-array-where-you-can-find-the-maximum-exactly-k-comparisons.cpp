class Solution {
public:
    const int mod=1e9+7;
    int dp[51][101][51];
    int solve(int &n,int &m,int k,int i,int mx)
    {
        if(i==n)
            return k==0;
        
        if(k<0)return 0;
        
        if(dp[i][mx][k]==0){
        
            dp[i][mx][k]=1;
            for(int val=1;val<=m;val++)
            {
                dp[i][mx][k]=(dp[i][mx][k]+solve(n,m,k-(mx<val),i+1,max(mx,val)))%mod;
            }
            // dp[i][mx][k]=ans;
        }
        return dp[i][mx][k]-1;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,0,sizeof dp);
        return solve(n,m,k,0,0);
    }
};