class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)     {
        int i=startPos[0],j=startPos[1];
        int x=homePos[0],y=homePos[1];
        int ans=0;
        if(i>x)
        {
            i--;
            while(i>=x)ans+=rowCosts[i--];
        }
        else
        {
            i++;
            while(i<=x)ans+=rowCosts[i++];
        }
        if(j>y)
        {
            j--;
            while(j>=y)ans+=colCosts[j--];
        }
        else
        {
            j++;
            while(j<=y)ans+=colCosts[j++];
        }
        return ans;
    }
};