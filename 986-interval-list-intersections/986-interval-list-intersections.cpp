class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(),m=b.size();
        
        int i=0,j=0;
        vector<vector<int>> ans;
        /*
        while(i<n && j<m)
        {
            if(a[i][0]<b[j][0])
            {
                if(a[i][1]>=b[j][0])
                {
                    ans.push_back({b[i][0],min(a[i][1],b[j][1])});
                    if(a[i][1]<=b[j][1])i++;
                    else j++;
                }
                else
                {
                    i++;
                }
            }
            else 
            {
                if(b[j][1]>=a[i][0])
                {
                    ans.push_back({a[i][0],min(a[i][1],b[j][1])});
                    if(a[i][1]<=b[j][1])i++;
                    else j++;
                }
                else
                {
                    j++;
                }
            }
                
        }
        */
        
        while(i<n && j<m)
        {
            int l=max(a[i][0],b[j][0]);
            int r=min(a[i][1],b[j][1]);
            if(l<=r)ans.push_back({l,r});
            
            if(a[i][1]<b[j][1])i++;
            else j++;
        }
        
        return ans;
    }
};