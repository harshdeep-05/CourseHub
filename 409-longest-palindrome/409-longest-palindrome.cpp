class Solution {
public:
    int longestPalindrome(string s) {
        int f[128]={0};
        int ans=0;
        for(char i:s)
        {
            f[i]++;
            if(f[i]==2)ans+=2,f[i]=0;
        }
        return ans+(ans<s.size());
    }
};