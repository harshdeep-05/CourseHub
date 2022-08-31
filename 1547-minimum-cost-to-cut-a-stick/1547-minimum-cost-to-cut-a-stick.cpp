class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& cuts)
    {
        if(j<i)
            return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int cost=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            cost=min(cost,cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts)+solve(k+1,j,cuts));
        }
        return  dp[i][j]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int m=cuts.size();
        sort(cuts.begin(),cuts.end());
        dp=vector<vector<int>> (m+1,vector<int>(m+1,-1));
        return solve(1,m-2,cuts);
    }
};