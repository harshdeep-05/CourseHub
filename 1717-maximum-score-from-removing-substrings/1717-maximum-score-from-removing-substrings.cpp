class Solution {
public:
    int remove(string &s,int x,string r)
    {
        int i=0,n=s.size(),cnt=0;
        for(int j=0;j<n;j++)
        {
            s[i++]=s[j];
            if(i>=2 && s[i-1]==r[1] && s[i-2]==r[0]){
                i-=2;
                cnt++;
            }
            
        }
        s.resize(i);
        return cnt*x;
    }
    int maximumGain(string s, int x, int y) {
        string a="ab",b="ba";
        if(x<y)
        {
            swap(a,b);
            swap(x,y);
        }
        return remove(s,x,a)+remove(s,y,b);
    }
};