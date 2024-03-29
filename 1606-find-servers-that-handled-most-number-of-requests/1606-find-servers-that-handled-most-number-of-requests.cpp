class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int maxReq = 0;
        set<int> availableServers;
        unordered_map<int,int>serverToReqCount;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i=0;i<k;i++)
            availableServers.insert(i);
        
        for(int i=0;i<arrival.size();i++){
            int start = arrival[i];
            int end = start + load[i];
            
            while(!pq.empty() && pq.top().first <= start){
                auto cur = pq.top();
                pq.pop();
                availableServers.insert(cur.second);
            }
            
            if(!availableServers.size())
                continue;
            
            int serverId = i % k;
            
            set<int>::iterator itr = availableServers.lower_bound(serverId);
            
            if(itr == availableServers.end()){
               itr = availableServers.begin();
            }
            
            serverToReqCount[*itr]++;
            maxReq= max(maxReq, serverToReqCount[*itr]);
            pq.push({end, *itr});
            
            availableServers.erase(itr);
  
        }
        
        vector<int>ans;
        
        for(auto p: serverToReqCount){
            if(p.second == maxReq)
                ans.push_back(p.first);
        }
        
        return ans;
    }
    
};