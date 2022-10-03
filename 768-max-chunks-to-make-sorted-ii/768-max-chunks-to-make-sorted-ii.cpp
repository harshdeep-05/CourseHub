class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> v=arr;
        sort(v.begin(),v.end());
        long long sum1=0,sum2=0,ans=0;
        for(int i=0;i<arr.size();i++)
        {
            sum1+=(long long)arr[i];
            sum2+=(long long)v[i];
            if(sum1==sum2)ans++;
        }
        return ans;
    }
};