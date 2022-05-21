class Solution {
public:
    /*
    int r[5]={1,0,-1,0,1};
    bool valid(vector<vector<int>> &graph,int i,int j)
    {
        int n=graph.size();
        return (i>=0 && i<n && j>=0 && j<n && graph[i][j]==0);
    }
    void dfs(vector<vector<int>> &graph,vector<vector<int>> &vis,int i,int j)
    {
        vis[i][j]=1;
        for(int d=0;d<4;d++)
        {
            if(valid(graph,i+r[d],j+r[d+1]) && !vis[i+r[d]][j+r[d+1]])
            {
                dfs(graph,vis,i+r[d],j+r[d+1]);
            }
        }
    }
    */
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};

    bool isValid(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if (i >= 0 and i < m and j >= 0 and j < n and grid[i][j] == 0)
            return true;
        return false;
    }

    void dfs(int i, int j, int m, int n, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
        visited[i][j] = true;
        for (int k=0; k<4; k++) {
            if (isValid(i+x[k],j+y[k], m, n, grid)) {
                if (!visited[i+x[k]][j+y[k]]) {
                    dfs(i+x[k], j+y[k], m, n, visited, grid);
                }
            }
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        /*if(grid.size()==0)return 0;
        int n=grid.size()*3;
        vector<vector<int>> graph(n,vector<int>(n,0));
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        for(int i=0;i<n/3;i++)
        {
            for(int j=0;j<n/3;j++)
            {
                if(grid[i][j]=='/')
                {
                    graph[i*3][i*3+2]=1;
                    graph[i*3+1][i*3+1]=1;
                    graph[i*3+2][i*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                    graph[i*3+2][i*3+2]=1;
                    graph[i*3+1][i*3+1]=1;
                    graph[i*3][i*3]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]==0 && !vis[i][j])
                {
                    dfs(graph,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
        */
        if (!grid.size()) return 0;
        int m = grid.size()*3;
        int n = grid[0].size()*3;
        vector<vector<int>> newGrid(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // Step 2. Fill in the new grid
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '/') {
                    newGrid[i*3][j * 3 + 2] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    newGrid[i * 3][j * 3] = 1;
                    newGrid[i * 3 + 1][j * 3 + 1] = 1;
                    newGrid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        // Step 3. Apply DFS from every single cell
        int count = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (newGrid[i][j] == 0 and !visited[i][j]) {
                    dfs(i, j, m, n, visited, newGrid);
                    count++;
                }
            }
        }
        // Step 4. Return count
        return count;
    }
};