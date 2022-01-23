class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> ans;
        for(int i=0;i<word.size();){
            if(word[i]>=48 and word[i]<=57){
                string s="";
                while(word[i]==48) i++;
                while(word[i]>=48 and word[i]<=57){
                    s+=word[i];
                    i++;
                }
                ans.insert(s);
            }
            else{
                i++;
            }
        }
        return ans.size();
    }
};