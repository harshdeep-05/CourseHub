class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n>m)return 0;  //if s2 is smaller than s1, always false
        
        vector<int> s1_f(26,0), window(26,0);  //store frequency of char of s1 and create a window of                                                        size (s1) to move in s2; 
        
        for(int i=0;i<n;i++)
        {
            s1_f[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
        
        if(s1_f==window)return 1;
        for(int i=n;i<m;i++)
        {
            window[s2[i-n]-'a']--;
            window[s2[i]-'a']++;
            if(s1_f==window)return 1;
        }
        return 0;
    }
};