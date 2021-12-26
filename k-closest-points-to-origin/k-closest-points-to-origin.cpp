class Solution {
public:
    int dist(int x,int y)
    {
        return (x*x +y*y);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>> > v;
        for(auto i:points)
        {
            v.push({-dist(i[0],i[1]),i});
        }
        vector<vector<int>> ans;
        while(k--)
        {
            auto x=v.top().second;
            v.pop();
            ans.push_back(x);
        }
        return ans;
            
    }
};