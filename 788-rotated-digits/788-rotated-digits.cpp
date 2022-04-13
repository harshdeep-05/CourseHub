class Solution {
public:
    int solve(int x,map<int,int> &m)
    {
        int num=0,i=0;
        while(x)
        {
            int d=x%10;
            if(d==4 || d==3 || d==7)return -1;
            else num+=m[d]*pow(10,i++);
            x/=10;
        }
        return num;
    }
    
    int rotatedDigits(int n) {
        int ans=0;
        map<int,int> m;
        m[0]=0;m[1]=1;m[2]=5;m[5]=2;m[6]=9;m[8]=8;m[9]=6;
        for(int i=1;i<=n;i++)
        {
            int y=solve(i,m);
            cout<<y<<" ";
            if(i!=y && y!=-1)ans++;
        }
        return ans;
    }
};