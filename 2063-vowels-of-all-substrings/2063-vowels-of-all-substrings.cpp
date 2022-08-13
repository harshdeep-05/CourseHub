class Solution {
public:
    long long countVowels(string word) {
        long long n=word.size(),vow=1,ans=0;
        for(auto c:word)
        {
            if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' )
            {
                ans+=vow*n;
                
            }
            vow++;
                n--;
        }
        return ans;
    }
};