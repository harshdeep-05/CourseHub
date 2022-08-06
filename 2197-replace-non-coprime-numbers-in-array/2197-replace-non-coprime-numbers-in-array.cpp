class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        s.push(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            
            while(!s.empty())
            {
                auto top=s.top();
                int gcd=__gcd(top,nums[i]);
                if(gcd==1){
                    s.push(nums[i]);
                    break;
                }
                s.pop();
                
                int lcm=(nums[i]/gcd)*top;
                nums[i]=lcm;
                if(s.empty())
                {
                    s.push(lcm);
                    break;
                }
            }
            
        }
        vector<int> ans(s.size());
        int i=s.size()-1;
        while(!s.empty())
        {
            ans[i--]=s.top();
            s.pop();
        }
        return ans;
            
    }
};