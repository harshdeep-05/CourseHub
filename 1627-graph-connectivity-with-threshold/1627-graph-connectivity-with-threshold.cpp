class Solution {
public:
    int N;
    vector<int> par;
    vector<int> rank;
    int find(int x)
    {
        if(par[x]==x)
            return x;
        
        return par[x]=find(par[x]);
    }
    
    void unionof(int x,int y)
    {
        x=find(x);
        y=find(y);
        
        if(x==y)return;
        
        if(rank[x]>rank[y])
        {
            par[y]=x;
        }
        else if(rank[y]>rank[x])
        {
            par[x]=y;
        }
        else
        {
            par[x]=y;
            rank[y]++;
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(),0);
        N=n+1;
        par=vector<int> (N);
        rank=vector<int> (N,0);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
        }
        for(int i=threshold+1;i<=n;i++)
        {
            for(int j=1;j*i<=n;j++)
            {
                if(j*i <= n && (j+1)*i <= n )
                    unionof(j*i, (j+1)*i);
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            find(i);
        }
        int i=0;
        for(auto v:queries)
        {
            int x=v[0],y=v[1];
            if(par[x]==par[y])
                ans[i]=true;
            
            i++;
        }
        return ans;
    }
};