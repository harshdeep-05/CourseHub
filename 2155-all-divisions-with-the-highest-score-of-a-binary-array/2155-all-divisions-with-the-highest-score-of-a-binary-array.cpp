class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size(),mx=0;
        /*
        for(int i=0;i<=n;i++)
        {
            int l=i-1,r=i,left=0,right=0;
            while(l>=0)left+=1-nums[l--];
            while(r<n)right+=nums[r++];
            m[i]=left+right;
            mx=max(m[i],mx);
        }
        */
        vector<int> left(n),right(n);
        left[0]=1-nums[0];
        for(int i=1;i<n;i++)
        {
            left[i]=1-nums[i]+left[i-1];
        }
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=nums[i]+right[i+1];
        }
        m[0]=right[0];
        m[n]=left[n-1];
        mx=max(m[0],m[n]);
        for(int i=1;i<n;i++)
        {
            m[i]=left[i-1]+right[i];
            mx=max(m[i],mx);
        }
        vector<int> ans;
        for(auto i:m)
        {
            if(i.second==mx)ans.push_back(i.first);
        }
        return ans;
        
    }
};