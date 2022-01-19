class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        int ans=0,n=time.size();
        if(!n)return 0;
        for(int i=0;i<n-1;i++)
        {
            ans+=min(time[i+1]-time[i],duration);
        }
        return ans+duration;
    }
};