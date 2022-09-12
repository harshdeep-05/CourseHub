class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size(),i=0,j=n-1;
        int score=0,ans=0;;
        while(i<=j && (power>=tokens[i] || score>0))
        {
            while(i<=j && power>=tokens[i])
            {
                score++;
                power-=tokens[i];
                i++;
            }
            ans=max(ans,score);
            if(score>0 && i<=j)
            {
                power+=tokens[j];
                score--;
                j--;
            }
        }
        return ans;
    }
};