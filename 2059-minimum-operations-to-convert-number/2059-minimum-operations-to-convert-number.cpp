class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        
        int moves=-1;
        unordered_map<int,int> m;
        while(!q.empty())
        {
            int s=q.size();
            moves++;
            while(s--)
            {
                auto x=q.front();
                q.pop();
                if(x==goal)return moves;
                
                if(x<0 || x>1000 || m.find(x)!=m.end())continue;
                
                m[x]++;
                for(auto i:nums)
                {
                    q.push(x+i);
                    q.push(x-i);
                    q.push(x^i);
                }
                
            }
        }
        return -1;
    }
};