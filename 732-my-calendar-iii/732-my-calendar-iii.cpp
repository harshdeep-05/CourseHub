class MyCalendarThree {
private:    
    map<int,int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        // auto it=m.begin()+1;
        int cur=0,ans=0;
        for(auto it:m)
        {
            cur+=it.second;
            ans=max(cur,ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */