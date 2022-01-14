class Solution {
public:
    bool is(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
            {
                if(is(s,i,j-1)||is(s,i+1,j))return true;
                return false;
            }
            
        }
        return true;
    }
};