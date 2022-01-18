class Solution {
public:
    int m,n,ans=INT_MAX;
    bool dp[71][5000];
    void solve(vector<vector<int>>& mat,int row,int target,int cur)
    {
        if(cur-ans >= target || (row >= 0 && dp[row][cur])) return;
        if(row==m)ans=min(ans,abs(cur-target));
        
        else
        {
            for(int i=0;i<n;i++)
            {
                solve(mat,row+1,target,cur+mat[row][i]);
            }
        }
                
        if(row>=0)dp[row][cur]=true;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m=mat.size(),n=mat[0].size();
        solve(mat,0,target,0);
        return ans;
    }
};