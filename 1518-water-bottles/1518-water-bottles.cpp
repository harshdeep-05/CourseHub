class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0,empty=0;
        while(numBottles||empty>=numExchange)
        {
            ans+=numBottles;
            empty+=numBottles;
            numBottles=empty/numExchange;
            empty%=numExchange;
        }
        return ans;
    }
};