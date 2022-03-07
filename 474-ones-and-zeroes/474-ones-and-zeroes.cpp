class Solution {
public:
    /*
    int dp[601][101][101];
    int solve(vector<string>& strs,int i, int m, int n,unordered_map<string,pair<int,int>> &cnt)
    {
        if(i<0)return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        auto x=cnt[strs[i]];
        
        if(x.first>m || x.second>n)
            return dp[i][m][n]=solve(strs,i-1,m,n,cnt);
        else
            return dp[i][m][n]=max(solve(strs,i-1,m,n,cnt),solve(strs,i-1,m-x.first,n-x.second,cnt)+1);
    }
    */
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*
        unordered_map<string,pair<int,int>> cnt;
        memset(dp,-1,sizeof dp);
        for(auto i:strs)
        {
            int a=0,b=0;
            for(auto c:i)
            {
                if(c=='0')a++;
                else b++;
            }
            cnt[i]={a,b};
        }
        return solve(strs,strs.size()-1,m,n,cnt);
        */
        
        int dp[m+1][n+1];
        memset(dp,0,sizeof dp);
        for(auto s:strs)
        {
            int a=0,b=0;
            for(auto c:s)
            {
                if(c=='0')a++;
                else b++;
            }
            
            for(int i=m;i>=0;i--)
            {
                for(int j=n;j>=0;j--)
                {
                    if(a<=i && b<=j)
                        dp[i][j]=max(dp[i][j],dp[i-a][j-b]+1);
                }
            }
        }
        return dp[m][n];
        
    }
};