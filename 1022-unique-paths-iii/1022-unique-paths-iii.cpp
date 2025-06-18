class Solution {
public:
    int n, m, total; // dimensions and total non-obstacle cells
    int ans = 0;

    void dfs(vector<vector<int>>& grid, int i, int j, int count) {
        // Check for out-of-bounds or hitting an obstacle
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1) return;

        if (grid[i][j] == 2) {
            if (count == total) ans++; // All non-obstacle squares visited
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1; // mark visited

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int dir = 0; dir < 4; dir++) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            dfs(grid, ni, nj, count + 1);
        }

        grid[i][j] = temp; // backtrack
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int sx = 0, sy = 0;
        total = 0;

        // Step 1: Count total walkable squares and locate the start
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) total++; // walkable
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(grid, sx, sy, 1); // count includes starting cell
        return ans;
    }
};
