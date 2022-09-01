class Solution {
public:
    unordered_map<int,int> m;
    int solve(int n)
    {
        if(n==0)
            return 0;
        if(m.find(n)!=m.end())return m[n];
        
        int a=n,b=n;
        a=n%2+solve(n/2);
        b=n%3+solve(n/3);
        return m[n]=min({a,b})+1;    
    }
    
    int minDays(int n) {
        // dp=vector<int> (n+1,-1);
        return solve(n)-1;
    }
};