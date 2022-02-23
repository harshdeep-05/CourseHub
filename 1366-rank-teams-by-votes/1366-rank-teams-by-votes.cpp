class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n=votes[0].size();
        vector<vector<int> > count(26,vector<int> (27));
        for(char c:votes[0])count[c-'A'][26]=c;
        
        for(auto s:votes)
        {
            for(int i=0;i<n;i++)
            {
                count[s[i]-'A'][i]--;
            }
        }
        sort(count.begin(),count.end());
        string ans;
        for(int i=0;i<n;i++)ans+=count[i][26];
        return ans;
            
    }
};