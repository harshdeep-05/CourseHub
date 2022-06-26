class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size(),m=n-k;
        int total_sum=0,mid_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=card[i];
            if(i<m)mid_sum+=card[i];
        }
        if(k==n)return total_sum;
        int ans=total_sum-mid_sum;
        int i=0,j=m;
        while(j<n)
        {
            mid_sum=mid_sum+card[j++]-card[i++];
            ans=max(ans,total_sum-mid_sum);
            //cout<<ans<<" ";
        }
        return ans;
    }
};