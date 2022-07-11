class Solution {
public:
    int fillCups(vector<int>& amount) {
        int mx=0,sum=0;
        for(auto i:amount)
        {
            mx=max(mx,i);
            sum+=i;
        }
        return max(mx,(sum+1)/2);
    }
};