class NumArray {
    vector<int> v,dec;
    int len;
public:
    NumArray(vector<int>& nums) {
        v=nums;
        double l=sqrt(nums.size());
        len=(int) ceil(nums.size()/l);
        dec=vector<int> (len);
        for(int i=0;i<nums.size();i++)
        {
            dec[i/len]+=nums[i];
        }
            
    }
    
    void update(int index, int val) {
        int i=index/len;
        dec[i]=dec[i]-v[index]+val;
        v[index]=val;
    }
    
    int sumRange(int left, int right) {
        int sum=0,start=left/len,end=right/len;
        
        if(start==end)
        {
            for(int k=left;k<=right;k++)sum+=v[k];
        }
        else
        {
            for(int k=left;k<(start+1)*len;k++)
            {
                sum+=v[k];
            }
            for(int k=start+1;k<end;k++)
            {
                sum+=dec[k];
            }
            for(int k=end*len;k<=right;k++)
            {
                sum+=v[k];
            }
            
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */