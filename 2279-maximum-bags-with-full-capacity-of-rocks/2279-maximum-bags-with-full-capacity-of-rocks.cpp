class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> ind;
        for(int i=0;i<capacity.size();i++)
        {
            ind.push_back(capacity[i]-rocks[i]);
        }
        
        sort(ind.begin(), ind.end());
        
        int i=0;
        while(additionalRocks>0 && i<ind.size() && additionalRocks>=ind[i])
        {
            cout<<ind[i]<<" ";
            additionalRocks-=ind[i];
            i++;
        }
        return i;
    }
};