class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int rows, int cols) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 1) return;
        grid[i][j] = 1;  // Mark as visited (water)
        dfs(grid, i + 1, j, rows, cols);
        dfs(grid, i - 1, j, rows, cols);
        dfs(grid, i, j + 1, rows, cols);
        dfs(grid, i, j - 1, rows, cols);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 1. Eliminate land cells connected to borders (not closed)
        for (int i = 0; i < rows; ++i) {
            if (grid[i][0] == 0) dfs(grid, i, 0, rows, cols);
            if (grid[i][cols - 1] == 0) dfs(grid, i, cols - 1, rows, cols);
        }
        for (int j = 0; j < cols; ++j) {
            if (grid[0][j] == 0) dfs(grid, 0, j, rows, cols);
            if (grid[rows - 1][j] == 0) dfs(grid, rows - 1, j, rows, cols);
        }

        // 2. Count remaining closed islands
        int count = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, rows, cols);
                    count++;
                }
            }
        }

        return count;
    }
};
