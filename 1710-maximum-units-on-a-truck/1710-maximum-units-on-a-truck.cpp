class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0,n=boxTypes.size();
        priority_queue<pair<int,int>> q;
        for(auto v:boxTypes)
        {
            q.push({v[1],v[0]});
        }
        while(!q.empty() && truckSize>0)
        {
            auto top=q.top();
            q.pop();
            
            if(truckSize>=top.second)
            {
                ans+=top.second*top.first;
                truckSize-=top.second;
            }
            else 
            {
                ans+=top.first*truckSize;
                truckSize=0;
            }
        }
        return ans;
    }
};