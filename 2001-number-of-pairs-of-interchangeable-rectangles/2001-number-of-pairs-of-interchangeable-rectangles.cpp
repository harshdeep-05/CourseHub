class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> m;
        long long ans=0;
        for(auto i:rectangles)
        {
            double d=double(i[0])/i[1];
            if(m.find(d)!=m.end())ans+=m[d];
            m[d]++;
            
        }
        
        return ans;
        
            
    }
};