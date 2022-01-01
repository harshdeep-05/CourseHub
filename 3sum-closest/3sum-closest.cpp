class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i,j,ans=1000000000,n=nums.size();
        for(int k=0;k<n-2;k++)
        {
            i=k+1;
            j=n-1;
            while(i<j){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==target)return sum;
            
            if(abs(target-ans)>abs(target-sum)){
                ans=sum;
            }
            if(sum<target)i++;
            if(sum>target)j--;
            }
        }
        return ans;
    }
};