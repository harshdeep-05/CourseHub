class SmallestInfiniteSet {
    int v[1001];
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)v[i]=1;
    }
    
    int popSmallest() {
        for(int i=1;i<=1000;i++)
        {
            if(v[i]==1)
            {
                v[i]--;
                return i;
            }
        }
        return 0;
    }
    
    void addBack(int num) {
        v[num]=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */