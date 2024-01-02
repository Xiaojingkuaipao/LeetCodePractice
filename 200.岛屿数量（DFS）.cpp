class Solution {
public:
    void DFS (vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + v[i][0];
            int ny = y + v[i][1];
            if (nx >= 0 && nx < a && ny >= 0 && ny < b && !visited[nx][ny] && grid[nx][ny] == '1') {
                DFS(grid, nx, ny, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        a = grid.size();
        b = grid[0].size();
        int count = 0;
        vector<vector<bool>>visited(a, vector<bool>(b, false));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    DFS(grid, i, j, visited);
                    count = count + 1;
                }
            }
        }
        return count;
    }
    private:
    int a, b;
    vector<vector<int>>v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
};
