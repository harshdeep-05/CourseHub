class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<int>& tasks,int T,int i,vector<int>& cur)
    {
        int n=tasks.size();
        if(cur.size()>=ans)return;
        if(i>=n)
        {
            int sz=cur.size();
            ans=min(ans,sz);
            return ;
        }
        cur.push_back(tasks[i]);
        solve(tasks,T,i+1,cur);
        cur.pop_back();
        
        for(int j=0;j<cur.size();j++)
        {
            if(cur[j]+tasks[i]<=T)
            {
                cur[j]+=tasks[i];
                solve(tasks,T,i+1,cur);
                cur[j]-=tasks[i];
            }
        }
        return;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        vector<int> cur;
        solve(tasks,sessionTime,0,cur);
        return ans;
    }
};