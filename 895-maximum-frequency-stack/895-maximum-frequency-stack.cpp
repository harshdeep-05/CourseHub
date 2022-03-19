class FreqStack {
private:
    unordered_map<int,int> m;
    priority_queue<vector<int>> pq;
    int pos=0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        pq.push({m[val],pos++,val});
    }
    
    int pop() {
        auto v=pq.top();
        pq.pop();
        m[v[2]]--;
        return v[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */