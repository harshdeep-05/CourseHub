class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> line(1002,0);
        for(auto v:trips)
        {
            line[v[1]]+=v[0];
            line[v[2]]-=v[0];
        }
        if(line[0]>capacity)return 0;
        for(int i=1;i<1002;i++){
            line[i]+=line[i-1];
            if(line[i]>capacity)return 0;
        }
        return 1;
    }
};