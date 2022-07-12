class Solution {
public:
    bool solve(vector<int> &v,int idx,vector<bool> &vis,int target,int k,int cur)
    {
        if(k==1)return 1;
        if(vis[idx])
        {
            if(idx==v.size()-1)return 0;
            return solve(v,idx+1,vis,target,k,cur);
        }
        
        vis[idx]=1;
        cur+=v[idx];
        
        if(cur>target)return 0;
        if(cur==target)return solve(v,0,vis,target,k-1,0);
        
        for(int i=idx+1;i<v.size();i++)
        {
            if(vis[i])continue;
            
            if(solve(v,i,vis,target,k,cur))
                return 1;
            vis[i]=0;
        }
        vis[idx]=0;
        cur-=v[idx];
        return 0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto i:matchsticks)sum+=i;
        if(sum%4)return 0;
        int side=sum/4;
        sort(begin(matchsticks),end(matchsticks));
        
        int k=4,n=matchsticks.size();
        if(matchsticks[n-1]>side)return 0;
        vector<bool> vis(n,0);
        return solve(matchsticks,0,vis,side,k,0);
    }
};