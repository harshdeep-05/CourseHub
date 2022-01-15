class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n=rungs.size(),ans=0;
        
        
        if(rungs[0]>dist)
        {
            ans+=rungs[0]/dist;
            if(rungs[0]%dist==0)ans--;
        }
        
        
        for(int i=1;i<n;i++)
        {
            if(rungs[i]-rungs[i-1]>dist){
                ans+=(rungs[i]-rungs[i-1])/dist;
                if((rungs[i]-rungs[i-1])%dist==0)ans--;
            }
            
        }
        return ans;
    }
};