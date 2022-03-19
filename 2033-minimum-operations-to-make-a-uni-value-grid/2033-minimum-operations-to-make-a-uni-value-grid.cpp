class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size(),t=0;
        int f=grid[0][0]%x;
        vector<int> v(m*n);
        for(auto i:grid)
        {
            for(auto j:i){
                v[t++]=j;
                if(j%x != f)return -1;
            }
        }
        sort(v.begin(),v.end());
        int j=m*n/2,ans=0;
        for(auto i:v)
        {
            ans+=(abs(i-v[j]))/x;
        }
        return ans;
    }
};