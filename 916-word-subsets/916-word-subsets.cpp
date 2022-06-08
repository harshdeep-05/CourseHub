class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v(26,0);
        for(auto b:words2)
        {
            vector<int> temp(26,0);
            for(auto c:b)temp[c-'a']++;
            for(int i=0;i<26;i++)v[i]=max(v[i],temp[i]);
        }
        
        vector<string> ans;
        for(auto a:words1)
        {
            vector<int> f(26,0);
            for(auto c:a)f[c-'a']++;
            int subset=1;
            for(int i=0;i<26;i++)
            {
                if(v[i]>f[i])
                {
                    subset=0;
                    break;
                }
            }
            if(subset)ans.push_back(a);
        }
        return ans;
    }
};