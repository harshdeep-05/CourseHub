class Solution {
public:
    int dp[201][201];
    int recursion(vector<vector<int>>& dungeon,int i,int j)
    {
        int n=dungeon.size(),m=dungeon[0].size();
        if(i==n-1 && j==m-1)
        {
            if(dungeon[i][j]>0)return dp[i][j]=0;
            return dp[i][j]=dungeon[i][j];
        }
        if(i>n-1 || j>m-1)return INT_MIN;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int l=recursion(dungeon,i+1,j);
        int r=recursion(dungeon,i,j+1);
        
        if(max(l,r)+dungeon[i][j]>0)
            return dp[i][j]=0;
        
        return dp[i][j]=max(l,r)+dungeon[i][j];
    }
        
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof dp);
        int ans=recursion(dungeon,0,0);
        
        if(ans<0)return (-1*ans+1);
        return 1;
    }
};