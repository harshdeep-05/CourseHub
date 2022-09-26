class Solution {
    vector<int> par,rank;
public:
    int findPar(int x)
    {
        if(par[x]==x)
            return x;
        return findPar(par[x]);
    }
    void unionof(int x,int y)
    {
        x=findPar(x);
        y=findPar(y);
        
        if(rank[x]<rank[y])
        {
            par[x]=y;
        }
        else if(rank[x]>rank[y])
        {
            par[y]=x;
        }
        else 
        {
            par[y]=x;
            rank[x]++;
        }
        return;
        
    }
    bool equationsPossible(vector<string>& equations) {
        par=vector<int> (26,0);
        rank=vector<int> (26,0);
        for(int i=0;i<26;i++)
        {
            par[i]=i;
        }
        
        for(auto v:equations)
        {
            int x=v[0]-'a',y=v[3]-'a';
            if(v[1]=='=')
                unionof(x,y);
        }
        
        for(auto v:equations)
        {
            int x=v[0]-'a',y=v[3]-'a';
            if(v[1]=='!' && findPar(x)==findPar(y))
                return 0;
        }
        return 1;
    }
};