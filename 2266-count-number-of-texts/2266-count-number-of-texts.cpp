class Solution {
public:
     int M = 1e9 + 7;
    int fn(int i ,string &arr , int n, vector<int> &dp){
        //base case
        if(i == 0) return 1;
        
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        
        ans = fn(i-1, arr, n, dp)%M;
        
        
        if(i-2 >= 0 and arr[i-2] == arr[i-1]){
            ans += fn(i-2, arr, n, dp);
            ans = ans%M;
            
            if(i-3 >= 0 and arr[i-3] == arr[i-2]){
                ans += fn(i-3, arr, n, dp);
                ans = ans%M;
                if((i-4 >= 0 and arr[i-4] == arr[i-3]) and (arr[i-4] == '7' or arr[i-4] == '9')){
                    ans += fn(i-4, arr, n, dp);
                    ans = ans%M;
                }
            }  
        }
 
        
        return dp[i] = ans;
    }
    
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        
        vector<int> dp(n+1 , -1);
        return fn(n ,pressedKeys, n, dp);
    }
};