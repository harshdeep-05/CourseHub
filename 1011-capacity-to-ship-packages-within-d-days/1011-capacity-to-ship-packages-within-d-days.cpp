class Solution {
public:
    bool solve(int m,vector<int>& weights, int days)
    {
        int cnt=1,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>m){
                cnt++;
                sum=weights[i];
            }
        }
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(),sum=0,mx=INT_MIN;
        for(auto i:weights)
        {
            sum+=i;
            mx=max(i,mx);
        }
        int ans,l=mx,r=sum;
        
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(solve(m,weights,days))
            {
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
        
        
    }
};