class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> last_idx(3,0);
        unordered_map<int,vector<int>> m;
        int n=garbage.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string s=garbage[i];
            vector<int> f(3,0);
            f[0]=count(s.begin(),s.end(),'M');
            f[1]=count(s.begin(),s.end(),'P');
            f[2]=count(s.begin(),s.end(),'G');
            if(f[0])last_idx[0]=i;
            if(f[1])last_idx[1]=i;
            if(f[2])last_idx[2]=i;
            
            ans+=f[0]+f[1]+f[2];
            
            m[i]=f;
        }
        for(int i=1;i<travel.size();i++)travel[i]+=travel[i-1];
        // int ans=0;
        if(last_idx[0])ans+=travel[last_idx[0]-1];
        if(last_idx[1])ans+=travel[last_idx[1]-1];
        if(last_idx[2])ans+=travel[last_idx[2]-1];
        return ans;
    }
};