class Solution {
public:
    int dp[101][101][601];
    int solve(vector<string>& strs, int m, int n,int index)
    {
        if(index<0)return 0;
        int count_0=count(strs[index].begin(),strs[index].end(),'0');
        int count_1=count(strs[index].begin(),strs[index].end(),'1');
        
        if(dp[m][n][index]!=-1)return dp[m][n][index];
        if(count_0<=m && count_1<=n )
        {
            return dp[m][n][index]=max(solve(strs,m,n,index-1),solve(strs,m-count_0,n-count_1,index-1)+1);
        }
        return dp[m][n][index]=solve(strs,m,n,index-1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int index=strs.size();
        memset(dp,-1,sizeof dp);
        return solve(strs,m,n,index-1);
    }
};