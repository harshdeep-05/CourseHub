class Solution {
public:
    void possibleSet(vector<vector<int>> &state,vector<int> &cur,int cols,int i,int &n)
    {
        if(cols==0)
        {
            state.push_back(cur);
            return;
        }
        for(int j=i;j<n;j++)
        {
            cur.push_back(j);
            possibleSet(state,cur,cols-1,j+1,n);
            cur.pop_back();
        }
        return;
    }
    void set(vector<vector<int>>& mat, int j)
    {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)mat[i][j]=99;
    }
    int check(vector<vector<int>> &mat)
    {
        int m=mat.size(),n=mat[0].size();
        int row=0;
        for(auto &i:mat)
        {
            int one=0,two=0;
            for(auto &j:i)
            {
                if(j==99)two++;
                else if(j==1)one++;
            }
            if(one && two)continue;
            row++;
        }
        return row;
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> state;
        vector<int> cur;
        possibleSet(state,cur,cols,0,n);
        int ans=0;
        for(auto c:state)
        {
            int cur=0;
            auto temp=mat;
            for(auto j:c)
            {
                set(temp,j);
            }
            cur=check(temp);
            ans=max(ans,cur);
        }
        return ans;
    }
};