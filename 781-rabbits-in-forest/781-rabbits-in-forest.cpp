class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int,int> m;
        for(auto i:answers)
        {
            if(m.count(i)==0)ans+=i+1;
            else m[i]++;
            if(m[i]==i)m.erase(i);
        }
        return ans;
    }
};