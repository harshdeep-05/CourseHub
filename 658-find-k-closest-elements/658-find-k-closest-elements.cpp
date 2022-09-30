class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0,h=n-1;
        vector<int> ans(k);
        k=n-k;
        while(k--)
        {
            if(abs(arr[l]-x)<=abs(arr[h]-x))h--;
            else l++;
        }
        for(int i=l;i<=h;i++)
        {
            ans[i-l]=arr[i];
        }
        return ans;
    }
};