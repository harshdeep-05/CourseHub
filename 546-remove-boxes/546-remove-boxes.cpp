class Solution {
public:
    int dp[101][101][101];
    int solve(vector<int>& v,int l,int r,int len)
    {
        if(l>r)
            return 0;
        
        if(dp[l][r][len]!=-1)
            return dp[l][r][len];
        int mx=(len+1)*(len+1) +solve(v,l+1,r,0);
        
        
        for(int i=l+1;i<=r;i++)
        {
            if(v[i]==v[l])
                mx=max(mx,solve(v,l+1,i-1,0)+solve(v,i,r,len+1));
        }
        return dp[l][r][len]=mx;
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,-1,sizeof dp);
        return solve(boxes,0,n-1,0);
    }
};