class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    /*
    int dp[10001][10001];
    int solve(vector<vector<int>>& c,int i,int day)
    {
        if(i==c.size())return 0;
        
        if(dp[i][day]!=-1)return dp[i][day];
        
        if(day+c[i][0]>c[i][1])
            return dp[i][day]=solve(c,i+1,day);
        
        return dp[i][day]=max(solve(c,i+1,day),
                   solve(c,i+1,day+c[i][0])+1);
        
        
    }*/
    int scheduleCourse(vector<vector<int>>& courses) {
        //memset(dp,-1,sizeof dp);
        sort(begin(courses),end(courses),comp);
        //return solve(courses,0,0);
        
        int sum=0,n=courses.size();
        priority_queue<int> q;
        for(auto i:courses)
        {
            sum+=i[0];
            q.push(i[0]);
            if(sum>i[1])
            {
                sum-=q.top();
                q.pop();
            }
        }
        return q.size();
        
    }
};