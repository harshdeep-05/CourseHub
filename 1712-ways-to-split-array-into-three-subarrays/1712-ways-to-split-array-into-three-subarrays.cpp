class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int mod=1e9+7;
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int left=pre[i],right=pre[n-1]-pre[i];
            if(left*2>right)break;
            
            int l=lower_bound(pre.begin()+i+1,pre.end()-1,left*2)-pre.begin();
            int r=upper_bound(pre.begin()+i+1,pre.end()-1,left+right/2)-pre.begin()-1;
            
            if(r-l+1>0)ans+=r-l+1;
            ans%=mod;
        }
        return ans;
            
    }
};