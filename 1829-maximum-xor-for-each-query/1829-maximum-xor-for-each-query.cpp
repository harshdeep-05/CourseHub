class Solution {
public:
    int solve(int n,vector<int> &k)
    {
        int index=k.size()-1;
        while(n)
        {
            int x=n%2;
            n/=2;
            if(x==k[index])k[index]=1-x;
            // ans=ans*2+k[index];
            index--;
        }
        int ans=0;
        for(auto i:k)
        {
            ans=ans*2+i;
        }
        return ans;
    }
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        for(int i=1;i<n;i++)nums[i]^=nums[i-1];
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            vector<int> k(maximumBit,1);
            ans[n-i-1]=solve(nums[i],k);
        }
        return ans;
    }
};