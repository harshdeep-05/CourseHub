class Solution {
    int ans=0;
    bool check(int n)
    {
        int x=sqrt(n);
        return (x*x==n);
    }
    void solve(vector<int>& nums,vector<int>& v,vector<bool>& vis)
    {
        if(v.size()==nums.size())
        {
            ans++;
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if((i==0 || vis[i-1] || nums[i]!=nums[i-1]) 
               && (v.size()==0 || check(nums[i]+v.back()))
               && !vis[i])
            {
                v.push_back(nums[i]);
                vis[i]=1;
                solve(nums,v,vis);
                vis[i]=0;
                v.pop_back();
            }
        }
        return ;
    }
public:
    int numSquarefulPerms(vector<int>& nums) {
        vector<int> v;
        vector<bool> vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        solve(nums,v,vis);
        return ans;
    }
};