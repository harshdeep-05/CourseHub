class Solution {
public:
    /*
    bool solve(vector<int> &target,int sum)
    {
        int n=target.size();
        if(sum==n)return 1;
        int x=max_element(target.begin(),target.end())-target.begin();
        int mx=target[x];
        if(2*mx-sum<1)return 0;
        target[x]=2*mx-sum;
        sum=sum-mx+target[x];
        return solve(target,sum);
    }
    */
    bool isPossible(vector<int>& target) {
        long long sum=0;
        priority_queue<int> q;
        for(auto i:target){
            sum+=i;
            q.push(i);
        }
        while(q.top()!=1)
        {
            sum-=q.top();
            if(sum==0 || sum>=q.top())return 0;
            int temp=q.top()%sum;
            if(temp==0 && sum!=1)return 0;
            q.pop();
            q.push(temp);
            sum+=temp;
            
        }
        return 1;
        //return solve(target,sum);
        
        
    }
};