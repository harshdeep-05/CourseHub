class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int> m;
        int count=0;
        for(auto i:jewels)m[i]=1;
        for(auto i:stones)
        {
            if(m.find(i)!=m.end())count++;
        }
        return count;
    }
};