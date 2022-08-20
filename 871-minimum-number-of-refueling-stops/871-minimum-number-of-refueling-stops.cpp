class Solution {
public:
//     vector<vector<vector<int>>>dp;
//     int solve(int idx,int tank,int prev_pos,int target,vector<vector<int>>& stations)
//     {
//         if(tank>=target)return 0;
//         if(idx==stations.size())return INT_MAX-1;
        
//         int x=stations[idx][0]-prev_pos,fuel=stations[idx][1];
//         tank-=x;
//         if(tank<0)return INT_MAX-1;
        
//         int stop=0,no_stop=0;
//         stop=solve(idx+1,tank+fuel,stations[idx][0],target-tank,stations)+1;
//         no_stop=solve(idx+1,tank,prev_pos,target,stations);
        
//         return min(stop,no_stop);
//     }
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        // dp=vector<vector<vector<int>>> (target+1, vector<vector<int>>(target+1, vector<int>(n+1, -1)));
        // int ans=solve(0,startFuel,0,target,stations);
        // if(ans>=INT_MAX-1)return -1;
        // return ans;
          int ans = 0;
        priority_queue<int> pq;
        for(auto s: stations) {
            
            while(startFuel < s[0] && pq.size()) {
                startFuel += pq.top();
                pq.pop();
                ans++;
            }      
            
            if(startFuel < s[0]) return -1;
            
            pq.push(s[1]);
        }
        
        while(startFuel < target && pq.size()) {
            startFuel += pq.top();
            pq.pop();
            ans++;
        }
        
        if(startFuel < target) return -1;
        
        return ans;

    }
};