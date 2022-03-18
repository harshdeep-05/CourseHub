class Solution {
public:
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size(),m=worker.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={difficulty[i],profit[i]};
        }
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        int mx=0,ans=0,i=0,cur=0;
        for(auto j:worker)
        {
            while(i<n && j>=v[i].first)mx=max(mx,v[i++].second);
            ans+=mx;
        }
        return ans;
        
        
    }
};