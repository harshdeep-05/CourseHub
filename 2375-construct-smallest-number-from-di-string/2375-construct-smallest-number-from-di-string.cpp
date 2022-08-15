class Solution {
public:
    string smallestNumber(string pattern) {
        string ans="";
        stack<int> s;
        int n=pattern.size();
        for(int i=0;i<=n;i++)
        {
            s.push(i+1);
            if(i==n || pattern[i]=='I')
            {
                while(!s.empty())
                {
                    ans+=s.top()+'0';
                    s.pop();
                }
            }
        }
        return ans;
    }
};