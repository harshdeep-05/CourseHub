class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,n=nums.size();
        for(auto i:nums)sum+=i;
        
        if(sum<x)return -1;
        if(sum==x)return n;
        
        int target=sum-x,maxLen=-1;
        sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==target)
            {
                maxLen=i+1;
            }
            if(m.find(sum)==m.end())m[sum]=i;
            if(m.find(sum-target)!=m.end())
            {
                maxLen=max(maxLen,i-m[sum-target]);
            }
        }
        return maxLen==-1?-1:n-maxLen;
    }
};