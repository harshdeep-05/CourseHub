class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=INT_MIN;
        for(int j=0;j<n;j++)
        {
            vector<int> pre_row(m,0);
            for(int r=j;r<n;r++)
            {
                for(int i=0;i<m;i++)pre_row[i]+=matrix[i][r];
                for(int i=0;i<m;i++)
                {
                    int sum=0;
                    for(int l=i;l<m;l++)
                    {
                        sum+=pre_row[l];
                        if(sum==k)return k;
                        if(sum<k)ans=max(ans,sum);
                    }
                }
            }
        }
        return ans;
    }
};