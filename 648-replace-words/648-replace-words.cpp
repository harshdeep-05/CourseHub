class Solution {
public:
    static bool yes(string a,string b)
    {
        return a.size()<b.size();
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(),dictionary.end(),yes);
        unordered_map<string,int> mp;
        int n=dictionary.size();
        for(int i=0;i<dictionary.size();i++)mp[dictionary[i]]=i;
        
        int i=0,m=sentence.size();
        string ans="";
        while(i<m)
        {
            string word="";
            int flag=0,root=0;;
            while(i<m && sentence[i]!=' ')
            {
                word+=sentence[i++];
                if(mp.find(word)!=mp.end() && flag==0)
                {
                    flag=1;
                    root=mp[word];
                    //cout<<word<<" ";
                }
                
            }
            if(flag)ans+=dictionary[root]+' ';
            else ans+=word+' ';
            i++;
                
        }
        ans.pop_back();
        return ans;
    }
};