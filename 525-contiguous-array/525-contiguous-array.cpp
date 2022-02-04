class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int sum=0,ans=0;
        //for(auto i:nums)if(i==0)i=-1;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i])sum+=1;
            else sum+=-1;
            if(m.find(sum)==m.end())m[sum]=i;
            else ans=max(ans,i-m[sum]);
            
        }
        return ans;
    }
};