class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];
        int maxPath = 1;
        for (auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxPath = max(maxPath, 1 + dfs(matrix, x, y));
            }
        }
        return dp[i][j] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res = max(res, dfs(matrix, i, j));
        return res;
    }
};
