// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int n, int w, int val[], int wt[],int cur)
    {
        if(n<=0)return 0;
        if(dp[n][cur]!=-1)return dp[n][cur];
        if(wt[n-1]+cur>w)return dp[n][cur]=solve(n-1,w,val,wt,cur);
        return dp[n][cur]=max(solve(n-1,w,val,wt,cur),solve(n,w,val,wt,cur+wt[n-1])+val[n-1]);
        
        
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp,-1,sizeof dp);
        return solve(N,W,val,wt,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends