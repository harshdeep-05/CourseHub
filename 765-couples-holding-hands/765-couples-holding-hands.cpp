class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int m[n],ans=0;
        for(int i=0;i<n;i++)m[row[i]]=i;
        
        for(int i=0;i<n;i+=2)
        {
            if(row[i]%2==0)
            {
                if(row[i+1]==row[i]+1)
                    continue;
                
                int idx=m[row[i]+1];
                m[row[i+1]]=idx;
                m[row[i]+1]=i+1;
                swap(row[i+1],row[idx]);
                ans++;
            }
            else
            {
                if(row[i+1]==row[i]-1)
                    continue;
                
                int idx=m[row[i]-1];
                m[row[i+1]]=idx;
                m[row[i]-1]=i+1;
                swap(row[i+1],row[idx]);
                ans++;
            }
        }
        return ans;
    }
};