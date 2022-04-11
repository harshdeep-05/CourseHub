class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0"; 
        
        int m=num1.size(),n=num2.size();
        vector<int> prod(m+n);
        for(int i=m-1;i>=0;i--)
        {
            int a=num1[i]-'0';
            for(int j=n-1;j>=0;j--)
            {
                int b=num2[j]-'0';
                int x=i+j+1;
                int p=a*b+prod[x];
                prod[x]=p%10;
                prod[x-1]+=p/10;
            }
        }
        
        int s=1;
        if(prod[0])s=0;
        string ans="";
        for(int i=s;i<m+n;i++)ans+=prod[i]+'0';
        
        return ans;
    }
};