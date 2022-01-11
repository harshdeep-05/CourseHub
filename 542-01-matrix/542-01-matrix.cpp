class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<pair<int,int>> z;
        
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)z.push_back({i,j});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    int cur=INT_MAX;
                    for(auto p:z)
                    {
                        int x=p.first,y=p.second;
                        if(abs(x-i)+abs(y-j)<cur)ans[i][j]=cur=abs(x-i)+abs(y-j);
                    }
                }
            }
        }
        return ans;
    }
};