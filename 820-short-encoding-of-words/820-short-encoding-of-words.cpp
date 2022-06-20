class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s;
        for(auto word:words)
        {
            s.insert(word);
        }
        for(auto word:words)
        {
            for(int i=1;i<word.size();i++)
            {
                s.erase(word.substr(i));
            }
        }
        int ans=0,n=0;
        for(auto i:s)
        {
            ans+=i.size()+1;
        }
        return ans;
    }
};