class Solution {
public:
    int mod=1e9+7;
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        long long sum = accumulate(packages.begin(), packages.end(), 0LL);        
        sort(packages.begin(), packages.end());
        
        for (auto &it: boxes) {
            sort(it.begin(), it.end());
        }
        
        const long long inf = 1e18;
        long long mod = 1e9 + 7;
        long long res = inf;
        
        for (int i = 0; i < (int)boxes.size(); i++) {
            long long ans = 0, prev = 0;
            for (int j = 0; j < (int)boxes[i].size(); j++) {
                int pos = upper_bound(packages.begin(), packages.end(), boxes[i][j]) - packages.begin() - 1;
                
                if (pos >= 0 && packages[pos] <= boxes[i][j]) {
                    long long x = boxes[i][j] * (pos - prev + 1);
                    ans = ans + x;
                    prev = pos + 1;
                }
            }
            
            if (prev == (int)packages.size())
                res = min(res, ans - sum);
        }
        
        if (res == inf) 
            res = -1;
        
        return (res % mod);
    }
};