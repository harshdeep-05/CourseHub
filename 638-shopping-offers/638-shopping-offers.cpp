class Solution {
public:
    int sum(vector<int>& needs,vector<int>& price)
    {
        int ans=0;
        for(int i=0;i<needs.size();i++)ans+=needs[i]*price[i];
        
        return ans;
    }
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        //base
        
        //without offer
        int j=0,ans=sum(needs,price);
        for(auto s:special)
        {
            vector<int> copy=needs;
            for(j=0;j<needs.size();j++)
            {
                int diff=copy[j]-s[j];
                if(diff<0)break;
                copy[j]=diff;
            }
            if(j==needs.size())
            {
                ans=min(ans,s[j]+solve(price,special,copy));
            }
        }
        return ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs);
    }
};