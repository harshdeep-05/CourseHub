class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size()-1,ans=0;
        vector<int> f(60,0);
        for(auto i:time){
            i=i%60;
            f[i]++;
        }
        ans=f[0]*(f[0]-1)+f[30]*(f[30]-1);
        ans/=2;
        int i=1,j=59;
        while(i<j)
        {
            ans+=(f[i]*f[j]);
            i++;
            j--;
        }
       
        return ans;
    }
};