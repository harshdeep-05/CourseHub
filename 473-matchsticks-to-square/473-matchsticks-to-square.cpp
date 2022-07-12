class Solution {
public:
     bool solve(vector<int> &nums,vector<bool> &visited,int index,int target,int k,int cur_sum)
    {
        if(k==0)return 1;
        if(visited[index]==true)
        {
            if(index==nums.size()-1)
                return false;
            return solve(nums,visited,index+1,target,k,cur_sum);
        }
        
        visited[index]=true;
        cur_sum+=nums[index];
        
        if(cur_sum>target)return 0;
        if(cur_sum==target)
            return solve(nums,visited,0,target,k-1,0);
        
        for(int i=index+1;i<nums.size();i++)
        {
            if(visited[i]==true)continue;
            if(solve(nums,visited,i,target,k,cur_sum))
                return true;
            
            visited[i]=0;
        }
        visited[index]=0;
        cur_sum-=nums[index];
        return 0;
        
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto i:matchsticks)sum+=i;
        if(sum%4)return 0;
        int side=sum/4;
        sort(rbegin(matchsticks),rend(matchsticks));
        if(matchsticks[0]>side)return 0;
        int k=4,n=matchsticks.size();
        vector<bool> vis(n,0);
        return solve(matchsticks,vis,0,side,3,0);
    }
};