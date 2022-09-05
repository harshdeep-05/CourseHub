class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.size();
        int ans=0,i=0,j=0;
        string vowel="aeiou";
        while(i<=n-5)
        {
            if(word[i]=='a')
            {
                j=i+1;
                int k=1;
                while(j<n)
                {
                    if(word[j]==word[j-1])j++;
                    else if(k<5 && word[j]==vowel[k])
                    {
                        j++;
                        k++;
                    }
                    else break;
                }
                if(k==5)
                {
                    ans=max(ans,j-i);
                }
                i=j;
            }
            else i++;
        }
        return ans;
    }
};