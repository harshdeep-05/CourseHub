class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n,0);
        //for(int i=0;i<n;i++)v[i]=i+1;
        int i=0,c=0,N=n;
        while(N)
        {
            if(v[i]==1)
            {
                i=(i+1)%n;
                continue;
            }
            c++;
            if(c==k)
            {
                v[i]=1;
                c=0;
                N--;
            }
            i=(i+1)%n;
            
        }
        if(i==0)return n;
        return i;
    }
};