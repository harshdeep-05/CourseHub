// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    
    int solve(int W, int wt[], int val[], int n,int cur)
    {
        if(n<=0)return 0;
        if(dp[n][cur]!=-1)return dp[n][cur];
        if(wt[n-1]+cur>W)return dp[n][cur]=solve(W,wt,val,n-1,cur);
        else return dp[n][cur]=max(solve(W,wt,val,n-1,cur+wt[n-1])+val[n-1],solve(W,wt,val,n-1,cur));
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      memset(dp,-1,sizeof dp);
       return solve(W,wt,val,n,0);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends