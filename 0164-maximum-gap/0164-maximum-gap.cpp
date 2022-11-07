class Solution {
public:
    int maximumGap(vector<int>& A) {
        int n=A.size();
    if(n<2)return 0;
    int mi=INT_MAX,mx=0;
    for(auto i:A)
    {
        mi=min(i,mi);
        mx=max(i,mx);
    }
    
    int gap=(mx-mi)/(n-1)+((mx-mi)%(n-1)>0);
    vector<int> mm(n,INT_MAX),nn(n,INT_MIN);
    
    for(int i=0;i<n;i++)
    {
        if(A[i]==mi || A[i]==mx)continue;
        int idx=(A[i]-mi)/gap;
        mm[idx]=min(mm[idx],A[i]);
        nn[idx]=max(nn[idx],A[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(mm[i]==INT_MAX)continue;
        ans=max(ans,mm[i]-mi);
        mi=nn[i];
    }
    ans=max(ans,mx-mi);
    return ans;
    }
};