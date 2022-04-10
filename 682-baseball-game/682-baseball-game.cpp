class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(auto i:ops)
        {
            if(i=="C")
            {
                s.pop();
            }
            else if(i=="D")
            {
                int x=s.top();
                s.push(x*2);
            }
            else if(i=="+")
            {
                int x=s.top();
                s.pop();
                int y=s.top();
                s.push(x);
                s.push(x+y);
                
            }
            else
            {
                s.push(stoi(i));
            }
        }
        int ans=0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};