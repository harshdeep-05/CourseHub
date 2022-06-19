class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
        int ans=0;
        long long val=0;
        for(int i=0;i<n;i++)
        {
            long long x=s[i]-'0';
            if(x*(pow(2,ans)+val)<=k){
                val+=x*(pow(2,ans));
                ans++;
            }
        }
        return ans;
    }
};