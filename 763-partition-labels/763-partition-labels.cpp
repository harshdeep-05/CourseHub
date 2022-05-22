class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(m.find(s[i])==m.end())m[s[i]]=i;
        }
        vector<int> ans;
        int j=0,part=0;
        for(int i=0;i<s.size();i++)
        {
            j=max(m[s[i]],j);
            if(i==j)
            {
                ans.push_back(i-part+1);
                part=i+1;
            }
        }
        return ans;
        
        
    }
};