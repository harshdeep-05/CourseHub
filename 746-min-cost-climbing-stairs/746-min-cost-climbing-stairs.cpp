class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int cur,x=cost[0],y=cost[1];
        
        for(int i=2;i<n;i++)
        {
            cur=cost[i]+min(x,y);
            x=y;
            y=cur;
        }
        return min(x,y);
    }
};