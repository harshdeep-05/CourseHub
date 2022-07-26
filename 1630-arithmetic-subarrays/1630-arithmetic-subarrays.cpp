class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size(),m=l.size();
        vector<bool> ans(m,1);
        for(int i=0;i<m;i++)
        {
            vector<int> v(r[i]-l[i]+1);
            for(int k=l[i];k<=r[i];k++)
                v[k-l[i]]=nums[k];
            
            sort(begin(v),end(v));
            for(int k=1;k<v.size();k++)
            {
                if(v[k]-v[k-1]!=v[1]-v[0])
                {
                    ans[i]=0;
                    break;
                }
            }
            
        }
        return ans;
        
    }
};