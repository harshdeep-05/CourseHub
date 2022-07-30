class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size(),k=n/3,x=0;
        long long ans=1e18;
        
        priority_queue<int> q1,q2;
        long long sum1=0,sum2=0;
        vector<long long> v1,v2;
        for(int i=0;i<2*k;i++){
            q1.push(nums[i]);
            sum1+=nums[i];
            
            while(q1.size()>k)
            {
                sum1-=q1.top();
                q1.pop();
            }
            if(q1.size()==k)v1.push_back(sum1);
        }
        for(int i=n-1;i>=k;i--)
        {
            q2.push(-nums[i]);
            sum2+=nums[i];
            while(q2.size()>k)
            {
                sum2+=q2.top();
                q2.pop();
            }
            if(q2.size()==k)v2.push_back(sum2);
        }
        reverse(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++)
        {
            ans=min(ans,v1[i]-v2[i]);
        }
        return ans;
    }
};