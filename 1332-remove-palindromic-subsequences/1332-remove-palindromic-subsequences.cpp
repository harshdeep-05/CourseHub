class Solution {
public:
    int removePalindromeSub(string s) {
        string a=s;
        for(int i=0;i<a.size()/2;i++)swap(a[i],a[a.size()-1-i]);
        if(a==s)return 1;
        return 2;
    }
};