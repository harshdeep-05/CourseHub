class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> q;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                q.push({((double)arr[j] / arr[i]), {arr[i], arr[j]}});
            }
        }
        while(k-->1)q.pop();
        auto a=q.top().second;
        return {a.first,a.second};
        
    }
};