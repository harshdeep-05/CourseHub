class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> x,y;
        for(auto i:words1)x[i]++;
        for(auto i:words2)y[i]++;
        
        int c=0;
        for(auto i:words1)
        {
            if(x[i]==1 && y[i]==1)c++;
        }
        return c;
    }
};