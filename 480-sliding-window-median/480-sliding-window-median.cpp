class Solution {
public:
    double median(vector<double>&q, int k)
    {
        double x;
        if(k%2 == 0)
             x=(double)(q[k/2]+q[k/2-1])/2;
        else
             x=(double)q[k/2];
        return x;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>v;
        vector<double>q;
        double d;
        int n=nums.size();
        int i=0, j=0;
        while(j < k)
        {
            q.push_back(nums[j]);
            j++;
        }
        sort(q.begin(), q.end());
        d = median(q, k);
        v.push_back(d);
        for(int k1=j; k1<nums.size(); k1++)
        {
            int init_pos = lower_bound(q.begin(), q.end(), nums[i])-q.begin();
            q.erase(q.begin()+init_pos);
            int last_pos = upper_bound(q.begin(), q.end(), nums[k1])-q.begin();
            q.insert(q.begin()+last_pos, nums[k1]);
            d = median(q, k);
            v.push_back(d);
            i++;
        }
        return v;
    }
};