class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        sort(p.begin(),p.end());
        int n=s.size(),m=p.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            int l=0,r=m-1;
            while(l<=r)
            {
                int m=l+(r-l)/2;
                long long x=(long long)p[m]*s[i];
                
                if(x<success)l=m+1;
                else r=m-1;
            }
            ans[i]=m-l;
        }
        return ans;
    }
};