class Solution {
public:
    vector<int> solve(vector<int>& nums)
    {
        int n=nums.size(),idx=0;
        vector<int> v,lis(n,0);
        for(auto &i:nums)
        {
            if(v.empty() || i>v.back())
                v.push_back(i);
            else
            {
                int x=lower_bound(v.begin(),v.end(),i)-v.begin();
                v[x]=i;
            }
            lis[idx++]=v.size();
        }
        return lis;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>rev=nums;
        reverse(rev.begin(),rev.end());
        
        vector<int> lis1=solve(nums);
        vector<int> lis2=solve(rev);
        
        int n=nums.size(),ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(lis1[i]!=1 && lis2[n-i-1]!=1)
                ans=max(ans,lis1[i]+lis2[n-i-1]-1);
        }
        return n-ans;
        
        
    }
};