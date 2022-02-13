class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2)
    {
        int x=p1[0]-p2[0],y=p1[1]-p2[1];
        return (x*x +y*y);
    }
    bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        double a=dist(p1,p2),b=dist(p1,p3),c=dist(p2,p3);
        if(a*b==0 || b*c==0 || c*dist(p1,p4) ==0)return 0;
        
        if(dist(p1,p4)==dist(p1,p2) && dist(p1,p3)==dist(p2,p4) && dist(p3,p4)==dist(p1,p2))return true;
        return false;
        
        
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        return (check(p1,p2,p3,p4) ||
                check(p1,p3,p2,p4) ||
                check(p1,p2,p4,p3)   );
    }
};