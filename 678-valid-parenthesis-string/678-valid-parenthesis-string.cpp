class Solution {
public:
    bool checkValidString(string s) {
        int l=0,h=0;
        for(auto &c:s)
        {
            if(c=='(')l++;
            else l--;
            if(c!=')')h++;
            else h--;
            if(h<0)break;
            l=max(0,l);
        }
        return l==0;
        
    }
};