class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int ans=0,neg=0,fi=n,li=0;
        int st=0;
        while(st<n)
        {
            int i=st;
            while(i<n && nums[i]!=0)
            {
                if(nums[i]<0)
                {
                    fi=min(fi,i);
                    li=i;
                    neg++;
                }
                i++;
            }
            if(neg%2==0)ans=max(ans,i-st);
            else
            {
                ans=max({ans,li-st,i-fi-1});
            }
            fi=n;
            neg=0;
            st=i+1;
        }
        return ans;
    }
};