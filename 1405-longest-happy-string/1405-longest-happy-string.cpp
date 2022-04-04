class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> v;
        if(a)v.push({a,'a'});
        if(b)v.push({b,'b'});
        if(c)v.push({c,'c'});
        
        string ans="";
        char pr1='.',pr2='.';
        while(!v.empty())
        {
            auto [x,c]=v.top();
            v.pop();
            
            if(pr1==c && pr2==c)
            {
                if(v.empty())return ans;
                auto [x2,c2]=v.top();
                v.pop();
                ans+=c2;
                pr2=pr1;
                pr1=c2;
                v.push({x,c});
                if(x2-1>0)v.push({x2-1,c2});
            }
            else
            {
                ans+=c;
                pr2=pr1;
                pr1=c;
                if(x-1>0)v.push({x-1,c});
            }
        }
        return ans;
        
    }
};