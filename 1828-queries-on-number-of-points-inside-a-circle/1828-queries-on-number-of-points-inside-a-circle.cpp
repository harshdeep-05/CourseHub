class Solution {
public:
    bool inside(vector<int> &j,int xc,int yc,int r)
    {
        double d=sqrt(pow(xc-j[0],2) +pow(yc-j[1],2));
        return d<=r;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=queries.size(),c=0;
        vector<int> ans(n,0);
        for(auto i:queries)
        {
            int xc=i[0],yc=i[1],r=i[2];
            
            for(auto j:points)
            {
                if(inside(j,xc,yc,r))ans[c]++;
            }
            c++;
        }
        return ans;
    }
};