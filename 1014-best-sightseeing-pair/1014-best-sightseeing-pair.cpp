class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        /* O(N*N) solution
            
        int n=values.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,values[i] + values[j] + i - j);
            }
        }
        return ans;
        
        */
        int n=values.size();
        int mx=values[0],ans=0;
        
        for(int i=1;i<n;i++)
        {
            ans=max(ans,mx+values[i]-i);
            mx=max(mx,values[i]+i);
        }
        return ans;
        
        
    }
};