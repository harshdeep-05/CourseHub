class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(1)
        {
            int i=s.find(part);
            if(s.find(part)==-1)break;
            s.erase(i,part.size());
        }
        return s;
    }
};