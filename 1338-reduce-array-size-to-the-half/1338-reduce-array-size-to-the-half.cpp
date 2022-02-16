class Solution {
public:
    
    
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr)m[i]++;
        int n=arr.size();
        vector<int> v;
        for(auto i:m)v.push_back(i.second);
        sort(v.begin(),v.end());
        int ans=0,sum=0,j=v.size()-1;
        while(j>=0)
        {
            if(sum>=n/2)break;
            ans++;
            sum+=v[j--];
        }
        return ans;
        
    }
};