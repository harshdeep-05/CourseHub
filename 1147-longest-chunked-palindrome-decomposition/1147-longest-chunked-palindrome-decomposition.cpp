class Solution {
public:
    int longestDecomposition(string text) {
        int ans=0,n=text.size();
        string copy=text;
        reverse(copy.begin(),copy.end());
        int i=0,flag=0;
        while(i<n )
        {
            flag=0;
            for(int len=1;len<n;len++)
            {
                string sub=text.substr(i,len);
                // cout<<sub<<" ";
                string sub2=copy.substr(i,len);
                reverse(sub2.begin(),sub2.end());
                if(sub2==sub){
                    ans++;
                    // cout<<sub<<" ";
                    i+=len;
                    // j+=len;
                    flag=1;
                    break;
                }
            }
            if(!flag)return 1;
            // j++;
        }
        return max(ans,1);
    }
};