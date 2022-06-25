class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag=0,n=nums.size();           
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                if(++flag > 1) return false;
                if(i == 1 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];    
                else nums[i] = nums[i-1];
            }
        }
        return true;
    }
};