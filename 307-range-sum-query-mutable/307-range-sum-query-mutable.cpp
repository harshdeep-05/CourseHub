class NumArray {
    vector<int> tree;
    int n;
public:
    void buildTree(vector<int>& nums)
    {
        for(int i=n,j=0;i<2*n;i++,j++)
            tree[i]=nums[j];
        for(int i=n-1;i>0;i--)
            tree[i]=tree[i*2]+tree[i*2+1];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree=vector<int> (2*n);
        buildTree(nums);
    }
    
    void update(int index, int val) {
        index+=n;
        tree[index]=val;
        while(index)
        {
            int left=index,right=index;
            if(index%2==0)right=index+1;
            else left=index-1;
            tree[index/2]=tree[left]+tree[right];
            index/=2;
        }
        return;
        
    }
    
    int sumRange(int left, int right) {
        left+=n;
        right+=n;
        
        int sum=0;
        while(left<=right)
        {
            if(left%2)
            {
                sum+=tree[left];
                left++;
            }
            if(right%2==0)
            {
                sum+=tree[right];
                right--;
            }
            left/=2;
            right/=2;
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