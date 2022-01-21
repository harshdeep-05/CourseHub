class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),tank=0,cur=0,ans=0;
        for(int i=0;i<n;i++)
        {
            tank+=gas[i]-cost[i];
            cur+=gas[i]-cost[i];
            if(cur<0)cur=0,ans=i+1;
        }
        if(tank<0)return -1;
        else return ans;
    }
};