class Solution {
public:
    bool yes(string a,string b)
    {
        int f[26]={0};
        for(auto c:a)f[c-'a']++;
        for(auto c:b){
            if(f[c-'a']>0)return 1;
        }
        return 0;
    }
    int maxProduct(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(yes(words[i],words[j]))continue;
                int l=words[i].size()*words[j].size();
                ans=max(ans,l);
            }
        }
        return ans;
    }
};