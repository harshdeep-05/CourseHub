class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        long long ans1=0,ans2=0,ans=0;
        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                ans1+=nums1[i++];
            }
            else if(nums1[i]>nums2[j])
            {
                ans2+=nums2[j++];
            }
            else
            {
                ans+=max(ans1,ans2)+nums1[i];
                ans1=0;
                ans2=0;
                i++;j++;
            }
        }
        while(i<n)ans1+=nums1[i++];
        while(j<m)ans2+=nums2[j++];
        ans+=max(ans1,ans2);
        return ans%mod;
    }
};