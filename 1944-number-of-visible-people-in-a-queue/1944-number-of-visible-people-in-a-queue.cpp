class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[i]>heights[s.top()])
            {
                int idx=s.top();
                s.pop();
                ans[idx]++;
            }
            if(!s.empty())ans[s.top()]++;
            s.push(i);
        }
        return ans;
    }
};