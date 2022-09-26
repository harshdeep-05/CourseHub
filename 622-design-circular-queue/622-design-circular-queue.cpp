class MyCircularQueue {
private:
    vector<int> v;
    int first,last,n;
    int size;
public:
    MyCircularQueue(int k) {
        n=k;
        v.resize(k);
        size=0;
    }
    
    bool enQueue(int value) {
        if(isFull())return 0;
        if(isEmpty())
        {
            first=0;last=0;
        }
        else last=(last+1)%n;
        
        v[last]=value;
        size++;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty())
            return 0;
        first=(first+1)%n;
        size--;
        return 1;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return v[first];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return v[last];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */