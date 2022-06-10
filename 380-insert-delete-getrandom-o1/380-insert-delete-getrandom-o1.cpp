class RandomizedSet {
    unordered_map<int,int> m;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(m.find(val)!=m.end())return 0;
        m[val]=nums.size();
        nums.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())return 0;
        int p=m[val];
        m[nums.back()]=p;
        swap(nums[p],nums.back());
        nums.pop_back();
        m.erase(val);
        return 1;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */