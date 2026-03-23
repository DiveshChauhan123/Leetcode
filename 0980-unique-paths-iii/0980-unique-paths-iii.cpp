class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited, int remain) {
        
        // boundary check FIRST
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;

        // obstacle or visited
        if (grid[i][j] == -1 || visited[i][j])
            return 0;

        // reached end
        if (grid[i][j] == 2) {
            return (remain == 1) ? 1 : 0;
        }

        visited[i][j] = 1;
        int count = 0;

        for (int k = 0; k < 4; k++) {
            int new_i = i + dx[k];
            int new_j = j + dy[k];

            count += solve(grid, new_i, new_j, visited, remain - 1);
        }

        visited[i][j] = 0; // backtrack
        return count;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int start_i, start_j;
        int empty = 0;

        // count empty + start
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }
                if (grid[i][j] != -1) empty++;
            }
        }

        return solve(grid, start_i, start_j, visited, empty);
    }
};