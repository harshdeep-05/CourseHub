class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n,vector<int> (n,0));
        vector<int> v(n,0);
        for(auto i:roads)
        {
            adj[i[0]][i[1]]=1;
            adj[i[1]][i[0]]=1;
            v[i[0]]++;
            v[i[1]]++;
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int cur=v[i]+v[j];
                if(adj[i][j])cur--;
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};