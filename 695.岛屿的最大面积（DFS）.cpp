class Solution {
public:
    int DFS(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= a || y < 0 || y >= b || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0; // 标记为已访问
        int area = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + v[k][0];
            int ny = y + v[k][1];
            area += DFS(grid, nx, ny);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        a = grid.size();
        b = grid[0].size();
        int result = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (grid[i][j] == 1) {
                    result = max(result, DFS(grid, i, j));
                }
            }
        }
        return result;
    }

private:
    int a, b;
    vector<vector<int>>v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
};
