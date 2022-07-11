class Solution {
public:
    bool canChange(string start, string target) {
        string a,b;
        for(auto c:start)if(c!='_')a+=c;
        for(auto c:target)if(c!='_')b+=c;
        if(a!=b)return 0;
        vector<int> l1,l2,r1,r2;
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='L')l1.push_back(i);
            else if(start[i]=='R')r1.push_back(i);
            
            if(target[i]=='L')l2.push_back(i);
            else if(target[i]=='R')r2.push_back(i);
        }
        for(int i=0;i<l1.size();i++)
        {
            if(l1[i]<l2[i])return 0;
        }
        for(int i=0;i<r1.size();i++)
        {
            if(r1[i]>r2[i])return 0;
        }
        return 1;
    }
};