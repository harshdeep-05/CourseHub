class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b)
    {
        if(a[0]-a[1]==b[0]-b[1])
            return a[1]<b[1];
        
        return (a[0]-a[1]<b[0]-b[1]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),comp);
        int ans=0,cur=0;
        for(auto i:tasks)
        {
            if(i[1]>cur)
            {
                ans+=i[1]-cur;
                cur=i[1];
            }
            cur-=i[0];
        }
        return ans;
    }
};