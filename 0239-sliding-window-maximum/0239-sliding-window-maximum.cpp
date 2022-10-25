class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> ans(n-k+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>> q;
        for(int i=0;i<k;i++)q.push({arr[i],i});
        ans[0]=q.top().first;
        for(int i=k;i<n;i++)
        {
            while(!q.empty() && q.top().first<arr[i])q.pop();
            while(!q.empty() && i-q.top().second>=k)q.pop();
            q.push({arr[i],i});
            ans[i-k+1]=q.top().first;
        }
        return ans;
            
    }
};