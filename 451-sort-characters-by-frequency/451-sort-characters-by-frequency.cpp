class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto i:s)m[i]++;
        priority_queue<pair<int,char>> q;
        for(auto i:m)
        {
            q.push({i.second,i.first});
        }
        string ans="";
        while(!q.empty())
        {
            char c=q.top().second;
            int n=q.top().first;
            q.pop();
            ans.append(n,c);
        }
        return ans;
        
    }
};