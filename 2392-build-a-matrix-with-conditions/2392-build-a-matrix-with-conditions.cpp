class Solution {
public:
    bool flag=1;
    void topo(vector<int> graph[],vector<int> &v,vector<int> &in)
    {
        queue<int> q;
        for(int i=1;i<in.size();i++)
        {
            if(in[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            v.push_back(node);
            for(auto it:graph[node])
            {
                in[it]--;
                if(in[it]==0)q.push(it);
            }
            cnt++;
        }
        if(cnt!=in.size()-1)
        {
            flag=0;
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<int> r[k+1],c[k+1];
        vector<int> in(k+1,0);
        for(auto v:rc)
        {
            r[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        vector<int> row;
        topo(r,row,in);
        in=vector<int>(k+1,0);
        
        for(auto v:cc)
        {
            c[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        
        vector<int> col;
        topo(c,col,in);
        
        if(!flag)return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        
        for(int i=1;i<=k;i++)
        {
            int x=find(row.begin(),row.end(),i)-row.begin();
            int y=find(col.begin(),col.end(),i)-col.begin();
            ans[x][y]=i;
        }
        
        return ans;
    }
};