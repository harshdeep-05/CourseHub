class Solution {
public:
    string maximumBinaryString(string binary) {
        int n=binary.size(),c=0,j=0;
        while(j<n && binary[j]=='1')j++;
        for(auto i:binary)c+=(i=='0');
        string ans(n,'1');
        if(c)ans[j+c-1]='0';
        return max(binary,ans);
    }
};