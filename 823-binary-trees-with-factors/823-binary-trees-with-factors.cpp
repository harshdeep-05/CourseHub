class Solution {
public:
    const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
            m[arr[i]]=i;
        
        // sort(arr.begin(),arr.end());
        
        vector<long> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j])continue;
                int x=arr[i]/arr[j];
                if(m.find(x)==m.end())continue;
                
                dp[i]=(dp[i]+dp[j]*dp[m[x]])%mod;
                
            }
        }
        long ans=0;
        for(auto i:dp)
        {
            ans=(ans+i)%mod;
        }
        return (int)ans%mod;
    }
    
};