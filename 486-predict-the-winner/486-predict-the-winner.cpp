class Solution {
public:
    int solve(vector<int> &nums,int i,int j,int turn)
    {
        if(i>=j)return turn*nums[i];
        
        int a=turn*nums[i]+solve(nums,i+1,j,-turn);
        int b=turn*nums[j]+solve(nums,i,j-1,-turn);
        
        return turn*max(turn*a,turn*b);
    }
    bool PredictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1,1)>=0;
    }
};