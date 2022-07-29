class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0,i=0,j=0;
        while(i<n && j<n)
        {
            j=i+1;
            while(j<n && prices[j-1]-prices[j]==1)
                j++;
            
            ans+=(j-i)*(j-i+1)/2;
            i=j;
        }
        ans+=(j-i)*(j-i+1)/2;
        return ans;
    }
};