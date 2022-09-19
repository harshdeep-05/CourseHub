class DSU{
private:
    vector<int> par,rank;
public:
    DSU(int n){
        par=vector<int> (n,0);
        for(int i=0;i<n;i++)par[i]=i;
        rank=vector<int> (n,1);
    }
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
        
        if(rank[x]<rank[y])swap(x,y);
        
        par[y]=x;
        rank[x]+=rank[y];
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(),0);
        DSU dsu(n+1);
        for(int i=threshold+1;i<=n;i++)
        {
            for(int j=i*2;j<=n;j+=i)
            {
                dsu.unionof(i,j);
            }
        }
        int i=0;
        for(auto v:queries)
        {
            int x=v[0],y=v[1];
            if(dsu.find(x)==dsu.find(y))
                ans[i]=true;
            i++;
        }
        return ans;
    }
};