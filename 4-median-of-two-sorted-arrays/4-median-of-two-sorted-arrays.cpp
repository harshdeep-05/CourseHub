class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size()+nums1.size();
        vector<int> q;
        int i=n/2,j=i-1;
        
        for(auto i:nums1)q.push_back(i);
        for(auto j:nums2)q.push_back(j);
        sort(q.begin(),q.end());
        
        if(n%2)
        {
            return q[i];
        }
        return (q[i]+q[j])/2.0;
        
    }
};