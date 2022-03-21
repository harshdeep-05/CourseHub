class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int mi=INT_MAX,c=0;
        long long sum=0;
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                if(j<0)c++;
                mi=min(mi,abs(j));
                sum+=abs(j);
            }
        }
        if(c%2==0)return sum;
        return sum-2*mi;
    }
};