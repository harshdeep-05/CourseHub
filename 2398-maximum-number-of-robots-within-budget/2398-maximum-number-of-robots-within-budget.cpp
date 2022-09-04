class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n=chargeTimes.size();
        map<int,int> m;
        long long sum=0,cost=0;
        int i=0,j=0,ans=0;
        while(j<n)
        {
            m[-chargeTimes[j]]++;
            sum+=runningCosts[j];
            j++;
            int mx=-m.begin()->first;
            cost=mx+sum*(j-i);
            if(cost<=budget)
            {
                ans=max(ans,j-i);
            }
            
            while(cost>budget)
            {
                cost-=mx;
                m.erase(-chargeTimes[i]);
                mx=-m.begin()->first;
                cost+=mx;
                sum-=runningCosts[i];
                i++;
                cost=mx+sum*(j-i);
            }
        }
        return ans;
        
    }
};