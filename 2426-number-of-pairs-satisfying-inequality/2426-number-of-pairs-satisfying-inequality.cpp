class Solution {
public:
    long long ans=0;
    int dif=0;
    void merge(vector<int>& v,int l,int m,int r)
    {
        vector<int> temp(r-l+1);
        int i=l,j=m+1,k=0;
        
        while(j<=r)
        {
            while(i<=m && v[i]-dif<=v[j])
            {
                i++;
            }
            j++;
            ans+=(long long)(i-l);
        }
        i=l;
        j=m+1;
        
        while(i<=m && j<=r)
        {
            if(v[i]<v[j])
                temp[k++]=v[i++];
            else temp[k++]=v[j++];
        }
        
        while(i<=m)temp[k++]=v[i++];
        while(j<=r)temp[k++]=v[j++];
        
        for(int i=0;i<(r-l+1);i++)
            v[i+l]=temp[i];
        
        return;
        
    }
    void mergeSort(vector<int>&a,int lo,int hi)
    {
        if(lo>=hi)
            return;
        int m=lo+(hi-lo)/2;
        mergeSort(a,lo,m);
        mergeSort(a,m+1,hi);
        merge(a,lo,m,hi);
        return;
    }
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n=a.size();
        dif=diff;
        for(int i=0;i<n;i++)a[i]-=b[i];
        mergeSort(a,0,n-1);
        return ans;
    }
};