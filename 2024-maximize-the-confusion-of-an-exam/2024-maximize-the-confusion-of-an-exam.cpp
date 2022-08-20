class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int j=0,x=0,ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='F')x++;
            while(x>k)
            {
                if(s[j++]=='F')x--;
            }
            ans=max(ans,i-j+1);
        }
        x=0;
        j=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='T')x++;
            while(x>k)
            {
                if(s[j]=='T')x--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};