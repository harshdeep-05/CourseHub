class Solution {
public:
    int minimumDeletions(string s) {
        int ans=0,b=0;
        for(auto c:s)
        {
            if(c=='b')b++;
            else 
            {
                if(b){ans++;
                b--;}
            }
        }
        return ans;
    }
};