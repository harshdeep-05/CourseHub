class Solution {
public:
    int dp[1001][1001];
    int func(string &s, string &t, int m, int n){
        if(n==0){
            return 1;
        }else if(m==0){
            return 0;
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        if(s[m-1]==t[n-1]){
            return dp[m][n]=func(s,t,m-1,n-1)+func(s,t,m-1,n);
        }else{
            return dp[m][n]=func(s,t,m-1,n);
        }  
    }
    

    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        memset(dp,-1,sizeof(dp));
        return func(s,t,m,n);
    }
};