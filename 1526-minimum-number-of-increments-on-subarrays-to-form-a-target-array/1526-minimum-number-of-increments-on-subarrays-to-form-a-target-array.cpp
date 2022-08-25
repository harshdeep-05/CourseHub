class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int ans=0,i=0,prev=0;
        stack<int> s;
        for(auto i:target)
        {
            if(s.empty() || i>=s.top())
                s.push(i);
            else 
            {
                ans+=s.top()-prev;
                s.pop();
                s.push(i);
                prev=i;
            }
        }
        ans+=s.top()-prev;
        return ans;
    }
};