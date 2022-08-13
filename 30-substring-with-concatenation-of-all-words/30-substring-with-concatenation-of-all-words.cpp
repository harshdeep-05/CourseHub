class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size(),m=words.size(),len=words[0].size();
        int window=m*len;
        
        unordered_map<string,int> mp;
        for(auto i:words)mp[i]++;
        
        int i=0;
        vector<int> ans;
        while(i<=n-window)
        {
            unordered_map<string,int> cnt;
            int j=i,flag=1;
            // // cout<<i<<" ";
            while(j<i+window)
            {
                string sub=s.substr(j,len);
                // cout<<sub<<" ";
                cnt[sub]++;
                if(mp.find(sub)==mp.end() || cnt[sub]>mp[sub])
                {
                    flag=0;
                    break;
                }
                j+=len;
            }
            if(flag)ans.push_back(i);
            i++;
        }
        
        return ans;
    }
};