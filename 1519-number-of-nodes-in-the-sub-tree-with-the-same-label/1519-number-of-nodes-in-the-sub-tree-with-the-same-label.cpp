class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
	    // build fast-lookup table
        vector<vector<int>> neighbors(n);
        for (auto &edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        
		// dfs
        vector<int> result(n);
        int table[26] = { 0 };
        dfs(result, 0, -1, neighbors, labels, table);
        
        return result;
    }
    
    void dfs(
        vector<int> &result,
        int i, 
        int from, 
        vector<vector<int>> &neighbors, 
        string &label, 
        int table[]) {
        
        for (int next : neighbors[i]) {
            if (next == from) continue;
            
            int temp[26] = { 0 };
            dfs(result, next, i, neighbors, label, temp);
            
            for (int i = 0; i < 26; ++i) table[i] += temp[i];
        }
        
        const char c = label[i];
        table[c - 'a']++;
        result[i] = table[c - 'a'];
    }
};