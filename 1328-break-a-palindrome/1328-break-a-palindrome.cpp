class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        if(palindrome.size()==1)return "";
        int i=0,n=palindrome.size();
        if(palindrome.size()%2 && palindrome[0]=='a')
        {
            palindrome[n-1]='b';
            return palindrome;
        }
        while(i<n)
        {
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
            i++;
        }
        palindrome[n-1]='b';
        return palindrome;
        
    }
};