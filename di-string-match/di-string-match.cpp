class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int> ans;
        int i=0,j=n,k=0;
        while(k<n)
        {
            if(s[k++]=='I')ans.push_back(i++);
            else ans.push_back(j--);
        }
        ans.push_back(i++);
        return ans;
    }
};