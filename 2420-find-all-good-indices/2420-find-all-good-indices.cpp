class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> left(n,1),right(n,1);
        int c=1;
        for(int i=2;i<n;i++)
        {
            if(nums[i-1]<=nums[i-2])
            {
                c++;
            }
            else c=1;
            left[i]=c;
        }
        c=1;
        for(int i=n-3;i>=0;i--)
        {
            if(nums[i+1]<=nums[i+2])
            {
                c++;
            }
            else c=1;
            right[i]=c;
        }
        vector<int> ans;
        for(int i=1;i<n-1;i++)
        {
            // cout<<left[i]<<right[i]<<"\n";
            if(left[i]>=k && right[i]>=k)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};