class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> m;
        long long ans=0;
        for(auto i:rectangles)
        {
            int x=__gcd(i[0],i[1]);
            pair<int,int> y={i[0]/x,i[1]/x};
            if(m.find(y)!=m.end())ans+=m[y];
            m[y]++;
            
        }
        
        return ans;
        
            
    }
};