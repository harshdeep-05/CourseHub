class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mi = INT_MAX;
        for(int i = 0; i<n; ++i)
        {
            if(nums[i]%2)nums[i] *= 2; 
            mx = max(mx,nums[i]);
            mi = min(mi,nums[i]);
        }
        
        int ans = mx - mi;
        priority_queue<int> pq;
        for(int i = 0; i<n; ++i)
        {
            pq.push(nums[i]);
        }
        
        while((pq.top()) % 2 == 0)
        {
            int top = pq.top();
            pq.pop(); 
            
            ans = min(ans, top - mi);
            top /= 2;
            mi = min(mi, top);  
            pq.push(top);   
        }
        
        ans = min(ans, pq.top() - mi);
        
        return ans;
        
    }
};