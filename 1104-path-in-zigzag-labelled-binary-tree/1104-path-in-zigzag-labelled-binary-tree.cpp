class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;

        int power = 0;
        int val = 1;
        while(2*val <= label)
        {
            power++;
            val *= 2;
        }

        int node = label;
        while(power >= 0)
        {
            
            ans.push_back(node);
            node = val - (node-val+2)/2;
            power--;
            val /= 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};