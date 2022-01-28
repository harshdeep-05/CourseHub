class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int a=INT_MIN,b=INT_MIN,c=INT_MIN,flag=1,f=1;
        for(auto i:nums){
            a=max(i,a);
        }
        for(auto i:nums)
        {
            if(i!=a)
            {
                b=max(i,b);
                flag=0;
            }
        }
        
        if(flag)return a;
        for(auto i:nums)
        {
            if(i!=a && i!=b)
            {
                c=max(i,c);
                f=0;
            }
        }
        if(f)return a;
        return c;
            
    }
};