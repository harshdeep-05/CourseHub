class UnionFind{
private:
    vector<int> par,rank;
public:
    UnionFind(int n)
    {
        par=vector<int>(n,0);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int x)
    {
        if(par[x]==x)
            return x;
        return find(par[x]);
    }
    void unionof(int x,int y)
    {
        x=find(x);
        y=find(y);
        
        if(rank[x]<rank[y])
        {
            par[x]=y;
        }
        else
        {
            par[y]=x;
            if(rank[x]==rank[y])rank[x]++;
        }
        return;
    }
    bool isConnected(int x,int y)
    {
        return find(x)==find(y);
    }
};

class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& v, vector<vector<int>>& queries) {
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<queries.size();i++)queries[i].push_back(i);
        sort(queries.begin(),queries.end(),comp);
        UnionFind uf(n);
        int i=0;
        vector<bool> ans(queries.size());
        for(auto &q:queries)
        {
            int x=q[0],y=q[1],limit=q[2],j=q[3];
            while(i<v.size() && v[i][2]<limit)
            {
                uf.unionof(v[i][0],v[i][1]);
                i++;
            }
            ans[j]=uf.isConnected(x,y);
        }
        return ans;
    }
};