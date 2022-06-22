class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> q;
        for(auto i:nums)q.push(i);
        
        for(int i=1;i<n;i+=2){
            nums[i]=q.top();
            q.pop();
        }
        for(int i=0;i<n;i+=2){
            nums[i]=q.top();
            q.pop();
        }
        return;
    }
};