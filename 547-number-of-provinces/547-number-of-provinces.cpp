class Solution {
public:
    void dfs(vector<vector<int>>& m,vector<int>& vis,int i)
    {
        vis[i]=1;
        for(int j=0;j<m.size();j++)
        {
            if(!vis[j] && m[i][j]==1)dfs(m,vis,j);
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(isConnected,vis,i);
                count++;
            }
        }
        return count;
    }
};