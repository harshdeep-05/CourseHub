class Solution {
public:
    int dp[2001][2001][2];
    int solve(vector<int>& arr, vector<int>& v,int i,int j,int prev,bool flag)
    {
        if(i==arr.size())return 0;
        if(dp[i][j][flag]!=-1)return dp[i][j][flag];
        j=upper_bound(v.begin(),v.end(),prev)-v.begin();
        
        if(arr[i]<=prev && j==v.size())return INT_MAX-1;
       
        int swap=2001,not_swap=2001;
        if(j<v.size())
            swap=1+solve(arr,v,i+1,j+1,v[j],1);
        
        if(arr[i]>prev)
            not_swap=solve(arr,v,i+1,j,arr[i],0);
        
        return dp[i][j][flag]=min(swap,not_swap);
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        memset(dp,-1,sizeof dp);
        
        sort(arr2.begin(),arr2.end());
        int ans=solve(arr1,arr2,0,0,-1,0);
        return (ans>arr2.size())?-1:ans;
    }
};