class Solution {
public:
    const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long> m;
//         for(int i=0;i<n;i++)
//             m[arr[i]]=i;
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]+=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j])continue;
                int x=arr[i]/arr[j];
                if(m.find(x)==m.end())continue;
                
                m[arr[i]]+=(m[x]*m[arr[j]])%mod;
                m[arr[i]]%=mod;
            }
            ans+=m[arr[i]];
            ans%=mod;
        }
        // long ans=0;
        // for(auto i:dp)
        // {
        //     ans=(ans+i)%mod;
        // }
        return ans;
    }
    
};