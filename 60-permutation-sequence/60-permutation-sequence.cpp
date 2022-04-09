class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> a;
        string s;
        for(int i=1; i<=n; i++)
        {
            s += i + '0';
        }
        
        do
        {
            a.push_back(s);
            
        }while(next_permutation(s.begin(), s.end()));
        
        return a[k-1];
    }
};