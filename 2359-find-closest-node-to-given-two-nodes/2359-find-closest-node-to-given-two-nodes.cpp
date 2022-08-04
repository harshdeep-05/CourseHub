class Solution {
public:
    void dfs(vector<int>& edges, int node, int dist,vector<int>& m)
    {
        if(node==-1 || m[node]!=-1)
            return;
        
        m[node]=dist;
        dfs(edges,edges[node],dist+1,m);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> m1(n,-1),m2(n,-1);
        
        dfs(edges,node1,0,m1);
        dfs(edges,node2,0,m2);
        int ans_idx=-1,dist=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(min(m1[i],m2[i])>=0 && dist>max(m1[i],m2[i]))
            {
                dist=max(m1[i],m2[i]);
                ans_idx=i;
            }
        }
        return ans_idx;
    }
};