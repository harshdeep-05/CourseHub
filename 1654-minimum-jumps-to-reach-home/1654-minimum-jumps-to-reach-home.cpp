class Solution {
public:
    unordered_map<int,int> m;
    int dp[6001][2];
    int solve(int &a,int &b,int &x,int cur,int prev)
    {
        if(cur==x)return 0;
        if(m.count(cur))return 6000;
        if(cur<0|| cur>6000)return 6000;
        
        if(dp[cur][prev]!=-1)
            return dp[cur][prev];
        // int forward=6001,backward=6001;
        dp[cur][prev]=1+solve(a,b,x,cur+a,0);
        if(prev==0)
            dp[cur][prev]=min(dp[cur][prev],1+solve(a,b,x,cur-b,1));
        
        return dp[cur][prev];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto& i:forbidden)
        {
            if(i==x)return -1;
            m[i]++;
        }
        memset(dp,-1,sizeof dp);
        int ans=solve(a,b,x,0,0);
        return (ans>=6000)?-1:ans;
    }
};