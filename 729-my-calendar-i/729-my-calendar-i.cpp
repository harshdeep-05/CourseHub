class MyCalendar {
    map<int,int> m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto i:m)
        {
            int x=i.first,y=i.second;
            if(x<end && y>start)
                return false;
        }
        m[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */