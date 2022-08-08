class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(auto i:nums)
        {
            if(v.empty() || i>v.back())
                v.push_back(i);
            else
            {
                /*
                int l=0,r=v.size()-1;
                while(l<r)
                {
                    int m=l+(r-l)/2;
                    if(v[m]<=i)
                        r=m-1;
                    else l=m+1;
                }
                if(l < v.size() && v[l] < i) {
                    l++;
                }
                */
                int l=lower_bound(v.begin(),v.end(),i)-v.begin();
                v[l]=i;
            }
            
        }
        return v.size();
        
        
    }
};