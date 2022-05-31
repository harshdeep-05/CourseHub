class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& arr,int i,int k,int maxm,int len)
    {
        if(i==arr.size())return maxm*len;
        
        
        int p=0,np=0;
        maxm=max(maxm,arr[i]);
        len++;
        if(dp[i][len]!=-1)return dp[i][len];
        if(len<k)
        {
            np=solve(arr,i+1,k,maxm,len);
        }
        p=len*maxm+solve(arr,i+1,k,0,0);
        
        return dp[i][len]=max(p,np);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof dp);
        return solve(arr,0,k,0,0);
    }
};