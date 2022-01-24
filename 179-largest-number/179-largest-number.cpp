class Solution {
public:
    static bool comB(int a,int b)
    {
        string x=to_string(a)+to_string(b);
        string y=to_string(b)+to_string(a);
        return x>y;
    }
    
    static bool comA(int a,int b)
    {
        int x=0,y=0;
        while(a)
        {
            x=x*10+a%10;
            a/=10;
        }
        while(b){
            y=y*10+b%10;
            b/=10;
        }
        
        while(x&&y)
        {
            if(x%10==y%10)
            {
                x/=10;y/=10;
            }
            else return (x%10>y%10);
        }
        if(x)return x%10;
        else return y%10;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comB);
        string ans="";
        
        for(auto i:nums)
        {
            //cout<<i<<" ";
            ans+=to_string(i);
        }
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};