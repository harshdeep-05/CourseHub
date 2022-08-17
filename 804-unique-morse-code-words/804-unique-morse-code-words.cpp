class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        vector<string> v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto w:words)
        {
            string cur="";
            for(auto c:w)
            {
                cur+=v[c-'a'];
            }
            s.insert(cur);
        }
        return s.size();
        
    }
};