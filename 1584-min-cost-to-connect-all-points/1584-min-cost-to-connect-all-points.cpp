class Solution {
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n = points.size(), ans = 0;
		priority_queue<vector<int>> pq;

		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
				pq.push({-d,i,j});
			}
		}

		int c = 0;
		UnionFind uf(n);
		while(c < n-1) {
			vector<int> cur = pq.top(); pq.pop();
			if(uf.Find(cur[1]) != uf.Find(cur[2])) {
				ans += -cur[0]; c++;
				uf.Union(cur[1],cur[2]);
			}
		}
		return ans;
	}

	class UnionFind{
	  vector<int> parent;
	public:
		UnionFind(int n){
			parent.resize(n);
			for(int i=0; i<n; i++)parent[i]=i;
		}
		int Find(int x){
			if(parent[x] != x)parent[x] = Find(parent[x]);
			return parent[x];
		}
		void Union(int x, int y){
			parent[Find(x)] = parent[Find(y)];
		}
	};
};