class Solution {
public:
    
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int ans=-1,cnt=0;
        vector<int> vis(n,0);
        vector<int> dist(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            int start=cnt,node=i;
            while(node!=-1)
            {
                cnt++;
                dist[node]=cnt;
                vis[node]=1;
                node=edges[node];
                
                if(node!=-1 && vis[node] )
                {
                    if(dist[node]>start)
                    {
                        ans=max(ans,cnt-dist[node]+1);
                    }
                    break;
                }
            }
        }
        
        return ans;
    }
};