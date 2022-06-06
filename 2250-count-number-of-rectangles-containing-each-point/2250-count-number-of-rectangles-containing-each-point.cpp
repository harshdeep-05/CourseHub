class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> v(101);
        sort(rectangles.begin(),rectangles.end());
        for(auto r:rectangles)
        {
            v[r[1]].push_back(r[0]);
        }
        vector<int> ans;
        for(auto p:points)
        {
            int x=p[0],y=p[1];
            int cnt=0;
            for(int j=y;j<101;j++)
            {
                if(v[j].size()==0)continue;
                int up=lower_bound(v[j].begin(),v[j].end(),x)-v[j].begin();
                cnt+=v[j].size()-up;
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};