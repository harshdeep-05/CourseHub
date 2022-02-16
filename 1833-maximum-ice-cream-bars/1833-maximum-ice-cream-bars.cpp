class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0,n=costs.size();
        for(;i<n && coins>=costs[i];i++){
            coins-=costs[i];
        }
        return i;
    }
};