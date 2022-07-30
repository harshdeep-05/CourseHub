class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f2(26,0);
        for(auto b:words2)
        {
            vector<int> f(26,0);
            for(auto c:b)f[c-'a']++;
            for(int i=0;i<26;i++)f2[i]=max(f2[i],f[i]);
        }
        vector<string> ans;
        for(auto a:words1)
        {
            vector<int> f(26,0);
            for(auto c:a)f[c-'a']++;
            int flag=1;
            for(int i=0;i<26;i++)
                {
                    if(f[i]<f2[i]){
                        flag=0;
                        break;
                    }
                }
            
            if(flag)ans.push_back(a);
        }
        return ans;
    }
};