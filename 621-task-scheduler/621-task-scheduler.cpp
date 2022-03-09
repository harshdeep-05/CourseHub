class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int cnt=0;
        for(auto i:tasks){
            m[i]++;
            cnt=max(cnt,m[i]);
        }
        int ans=(cnt-1)*(n+1);
        for(auto c:m)
        {
            if(c.second==cnt)ans++;
        }
        return max((int)tasks.size(),ans);
        
        
    }
};