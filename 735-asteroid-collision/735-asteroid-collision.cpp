class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        stack<int> s;
        vector<int> ans;
        for(auto i:asteroids)
        {
            if(s.empty()||i>0)s.push(i);
            else
            {
                while(!s.empty() and s.top() > 0 and s.top() < abs(i)) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(i)) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(i);
                    }
                }
            }
        }
        while(!s.empty())ans.push_back(s.top()),s.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};