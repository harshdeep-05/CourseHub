class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size(),mod=1e9+7;
        //unordered_map<int,int> m;
        //for(auto i:arr)m[i]++;
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=target-arr[i];
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(arr[k]+arr[j]>x)k--;
                else if(arr[k]+arr[j]<x)j++;
                else
                {
                    if(arr[j]==arr[k])
                    {
                        ans+=(k-j+1)*(k-j)/2;
                        ans%=mod;
                        break;
                    }
                    else
                    {
                        int l=1,r=1;
                        while(j+1<k && arr[j]==arr[j+1])l++,j++;
                        while(k-1>j && arr[k]==arr[k-1])k--,r++;
                        
                        ans=(ans+l*r)%mod;
                        j++;
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};