class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int n=piles.size(),i=0,j=1,k=n-1;
        int ans=0;
        while(j<k)
        {
            ans+=piles[j];
            j+=2;
            k--;
        }
        return ans;
    }
};