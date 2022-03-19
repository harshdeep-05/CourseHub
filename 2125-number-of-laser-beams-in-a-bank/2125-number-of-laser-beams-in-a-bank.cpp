class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size(),n=bank[0].size();
        vector<int> v;
        for(int i=0;i<m;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                c+=bank[i][j]-'0';
            }
           if(c)v.push_back(c);
        }
        int ans=0;
        for(int i=1;i<v.size();i++)
        {
            ans+=v[i]*v[i-1];
        }
        return ans;
    }
};