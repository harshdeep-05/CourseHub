class Solution {
public:
    int ans=0;
    bool valid(vector<int> &box)
    {
        for(auto i:box)
        {
            if(i)return 0;
        }
        return 1;
    }
    
    void solve(int n,vector<int>& box,vector<vector<int>>& r,int i,int cur)
    {
        if(valid(box))
        {
            ans=max(ans,cur);
        }
        if(ans>=cur+r.size()-i)return;
        if(i==r.size())
            return;
        
        for(int j=i;j<r.size();j++)
        {
            box[r[j][0]]--;
            box[r[j][1]]++;
            solve(n,box,r,j+1,cur+1);
            box[r[j][0]]++;
            box[r[j][1]]--;
        }
        
        // solve(n,box,r,i+1,cur+1);
        return;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> box(n,0);
        solve(n,box,requests,0,0);
        return ans;
    }
};