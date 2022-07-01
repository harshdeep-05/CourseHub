class Solution {
public:
    /*vector<int> ans;
    void merge(vector<vector<int>> &v,int start,int mid,int end)
    {
        int l_sz=mid-start;
        int r_sz=end-mid+1;
        vector<vector<int>> left(l_sz+1),right(r_sz+1);
        
        for(int i=0;i<l_sz;i++)
            left[i]=v[i+start];
        for(int i=0;i<r_sz;i++)
            right[i]=v[i+mid];
        
        left[l_sz]=right[r_sz]={INT_MAX,-1};
        
        int l_idx=0,r_idx=0;
        
        for(int i=start;i<=end;i++)
        {
            if(left[l_idx][0]<=right[r_idx][0])
            {
                v[i]=left[l_idx];
                ans[left[l_idx][1]]+=r_idx;
                l_idx++;
            }
            else 
            {
                v[i]=right[r_idx];
                r_idx++;
            }
        }
        return;
    }
    void mergesort(vector<vector<int>> &v,int start,int end)
    {
        if(start==end)return;
        
        int mid=start+(end-start)/2;
        mergesort(v,start,mid);
        mergesort(v,mid+1,end);
        merge(v,start,mid+1,end);
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans=vector<int> (n,0);
        vector<vector<int>> v(n);
        for(int i=0;i<n;i++)v[i]={nums[i],i};
        
        mergesort(v,0,n-1);
        return ans;
    }*/
    vector<int> ans;
    
    void merge(int l, int mid, int r, vector<pair<int,int>> &a) {
        int m = mid-l, n = r-mid+1;
        vector<pair<int,int>> a1(m+1), a2(n+1);
        for(int i=0; i<m; i++) {
            a1[i].first = a[i+l].first;
            a1[i].second = a[i+l].second;
        }
        for(int i=0; i<n; i++) {
            a2[i].first = a[i+mid].first;
            a2[i].second = a[i+mid].second;
        }
        a1[m].first = a2[n].first = INT_MAX;
        a1[m].second = a2[n].second = -1;
        int li=0, ri=0;
        for(int i=l; i<=r; i++) {
            if(a1[li].first<=a2[ri].first) {
                a[i].first=a1[li].first;
                a[i].second=a1[li].second;
                ans[a1[li].second]+=ri;
                li++;
            } else {
                a[i].first=a2[ri].first;
                a[i].second=a2[ri].second;
                ri++;
            }
        }
    }

    void mergeSort(int l, int r, vector<pair<int,int>> &a) {
        if(l==r) return;
        int mid = l+((r-l)>>1);
        mergeSort(l, mid, a); mergeSort(mid+1, r, a);
        merge(l,mid+1,r,a);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans = vector<int> (n,0);
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++) 
            a.push_back({nums[i],i});
        mergeSort(0,n-1,a);
        return ans;
    }
};