class Solution {
public:
    int to_minutes(string s)
    {
        return ((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
    }
    
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans=INT_MAX,n=timePoints.size();
        for(int i=1;i<n;i++)
        {
            int c=to_minutes(timePoints[i]);
            int p=to_minutes(timePoints[i-1]);
            
            ans=min(ans,c-p);
        }
        int last=abs(to_minutes(timePoints[n-1])-to_minutes(timePoints[0])-1440);
        ans=min(last,ans);
        return ans;
    }
};