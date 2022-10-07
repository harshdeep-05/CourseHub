class MyCalendarThree {
private:    
    unordered_map<int,int> arr,tree;
public:
    MyCalendarThree() {
        
    }
    
    void query(int l,int r,int start,int end,int node)
    {
        if(start>r || end<l)return;
        if(l>=start && r<=end)
        {
            tree[node]++;
            arr[node]++;
        }
        else
        {
            int mid=l+(r-l)/2;
            query(l,mid,start,end,node*2);
            query(mid+1,r,start,end,node*2+1);
            
            tree[node]=arr[node]+max(tree[node*2],tree[node*2+1]);
        }
        return;
    }
    
    int book(int start, int end) {
        // m[start]++;
        // m[end]--;
        // // auto it=m.begin()+1;
        // int cur=0,ans=0;
        // for(auto it:m)
        // {
        //     cur+=it.second;
        //     ans=max(cur,ans);
        // }
        // return ans;
        
        query(1,1e9,start,end-1,1);
        return tree[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */