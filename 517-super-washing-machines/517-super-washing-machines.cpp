class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size(),sum=0;
        for(auto &i:machines)sum+=i;
        if(sum%n)return -1;
        sum/=n;
        int ans=0,prefix=0;
        for(auto &i:machines)
        {
            ans=max({ans,i-sum,abs(prefix)});
            prefix+=i-sum;
        }
        return ans;
    }
};