class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &cur,int n,int k,int i)
    {
        if(cur.size()==k)
        {
            ans.push_back(cur);
            return;
        }
        if(i>n)return;
        for(int j=i;j<=n;j++)
        {
            cur.push_back(j);
            solve(ans,cur,n,k,j+1);
            cur.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans,cur,n,k,1);
        return ans;
    }
};