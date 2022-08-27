class Solution {
public:
    vector<int> count(int n)
    {
        vector<int> v(10,0);
        while(n)
        {
            v[n%10]++;
            n/=10;
        }
        return v;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> v=count(n);
        for(int i=0;i<31;i++)
        {
            //cout<<(1<<i)<<"\n";
            if(v==count(1<<i))return true;
        }
        return false;
        
        
    }
};