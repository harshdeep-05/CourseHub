class Solution {
public:
    vector<string> split(string s)
    {
        vector<string> w;
        stringstream ss(s);
        string word;
        while(ss>>word)w.push_back(word);
        
        return w;
    }
    bool areSentencesSimilar(string s1, string s2) {
        if(s1==s2)return true;
        int m=s1.size(),n=s2.size();
        
        if(m<n)
            return areSentencesSimilar(s2,s1);
        
        vector<string> w1,w2;
        w1=split(s1);
        w2=split(s2);
        m=w1.size(),n=w2.size();
        int i=m-1,j=n-1;
        //added at start
        int x=0;
        while(x<=n-1 && w1[x]==w2[x])
        {
            x++;
        }
        while(j>=x && w1[i]==w2[j])
        {
            i--;j--;
        }
        return (j<x);
        
    }
};