class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix[0].size(),x=0;
        priority_queue<int> q;
        for(auto i:matrix)
        {
            for(auto j:i)q.push(-j);
        }
        while(k-->1)q.pop();
        return -q.top();
    }
};