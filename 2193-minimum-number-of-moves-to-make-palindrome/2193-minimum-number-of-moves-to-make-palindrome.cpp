class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size(),ans=0;
        while(n)
        {
            int i=0;
            while(s[i]!=s[n-1])i++;
            if(i==n-1)
            {
                ans+=(n-1)/2;
            }
            else
            {
                ans+=i;
                s.erase(s.begin()+i);
                n--;
            }
            s.pop_back();
            n--;
        }
        return ans;
    }
};