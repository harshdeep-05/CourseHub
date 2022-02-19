class Solution {
public:
    int ans=0;
    void solve(vector<int>& vis,int n,int x)
    {
        if(x>n)ans++;
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && (x%i==0 || i%x==0) )
            {
                vis[i]=1;
                solve(vis,n,x+1);
                vis[i]=0;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int> vis(n+1);
        solve(vis,n,1);
        return ans;
    }
};