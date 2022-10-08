class RangeModule {
    map<int,int> m;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it=m.lower_bound(left);
        if(it!=m.begin() && prev(it)->second>=left)--it;
        
        while(it!=m.end() && it->first<=right)
        {
            left=min(left,it->first);
            right=max(right,it->second);
            m.erase(it++);
            // it++;
        }
        m[left]=right;
        return;
    }
    
    bool queryRange(int left, int right) {
        auto it=m.lower_bound(left);
        if(it!=m.begin() && prev(it)->second>=left)it--;
        
        if(it==m.end())return 0;
        return (it->first<=left && it->second>=right);
    }
    
    void removeRange(int left, int right) {
        auto it=m.lower_bound(left);
        if(it!=m.begin() && prev(it)->second>=left)it--;
        
        vector<pair<int,int>> v;
        while(it!=m.end() && it->first<right)
        {
            if(it->first<left)
            {
                v.push_back({it->first,left});
            }
            if(it->second>right)
            {
                v.push_back({right,it->second});
            }
            m.erase(it++);
            // it++;
        }
        for(auto &p:v)
        {
            m[p.first]=p.second;
        }
        return;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */