class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        queue<int> q;
        for(auto i:initialBoxes){
            q.push(i);
            for(auto key:keys[i])status[key]=1;
        }
        
        //vector<bool> vis(n,0);
        
        int candies_collected=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int box=q.front();
                q.pop();
                if(status[box] && candies[box])
                {
                    candies_collected+=candies[box];
                    candies[box]=0;
                }
                //for(auto key:keys[box])status[key]=1;
                for(auto i:containedBoxes[box])
                {
                    for(auto key:keys[i])status[key]=1;
                }
                
                for(auto i:containedBoxes[box])
                {
                    if(candies[i] && status[i])q.push(i);
                }
                
                //vis[box]=1;
            }
        }
        return candies_collected;
    }
};