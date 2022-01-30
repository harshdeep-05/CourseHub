class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>busStopNo;
        
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                busStopNo[routes[i][j]].push_back(i);
            }
        }
        
        unordered_map<int,bool>visBusNo;
        unordered_map<int,bool>visBusStopNo;
        int buses=0;
        queue<int>q;
        
        q.push(source);
        visBusStopNo[source]=true;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int node=q.front();
                q.pop();
                
                if(node==target)
                    return buses;
                
                for(auto x:busStopNo[node])
                {
                    if(!visBusNo[x])
                    {
                        for(auto y:routes[x])
                        {
                            if(!visBusStopNo[y])
                            {
                                q.push(y);
                                visBusStopNo[y]=true;
                            }
                        }
                        visBusNo[x]=true;
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};