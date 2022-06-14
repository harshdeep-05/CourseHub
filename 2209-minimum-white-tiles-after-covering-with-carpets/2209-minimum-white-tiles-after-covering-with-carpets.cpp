class Solution {
private:
    int dp[1001][1001];
    int solve(string& floor,int idx,int n,int car,int len,vector<int>&prefix)
    {
        if(idx==n || car==0)
            return 0;
        
        if(dp[idx][car]!=-1)
            return dp[idx][car];
        
        int range=min(idx+len-1,n-1);
        int cnt=prefix[range];
        
        if(idx>0)
            cnt-=prefix[idx-1];
        
        int pick=cnt+solve(floor,min(idx+len,n),n,car-1,len,prefix);
        int skip=solve(floor,idx+1,n,car,len,prefix);
        return dp[idx][car]=max(pick,skip);
    }
public:
    int minimumWhiteTiles(string floor, int Carpet, int carpetLen) {       
        
        memset(dp,-1,sizeof dp);
        int n=floor.size();
        vector<int>prefix(n,0);
        int cnt=0;
        for(auto i=0;i<n;++i)
        {
            if(floor[i]=='1')
                cnt++;
            
            prefix[i]=cnt;
        
        }
        return cnt-solve(floor,0,floor.size(),Carpet,carpetLen,prefix);
        
    }
};