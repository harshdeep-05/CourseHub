class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto i:nums)s.insert(i);
        
        int ans=0;
        for(auto i:s)
        {
            if(s.find(i-1)==s.end())
            {
                int len=0;
                int x=i;
                while(s.find(x)!=s.end())
                {
                    x++;
                    len++;
                }
                ans=max(len,ans);
            }
        }
        return ans;
    }
};