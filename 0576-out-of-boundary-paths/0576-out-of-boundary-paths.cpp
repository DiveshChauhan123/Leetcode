class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[51][51][51];

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    int solve(int m, int n, int maxMove, int i, int j) {
        // ✅ Out of boundary → count 1 path
        if (i < 0 || j < 0 || i >= m || j >= n) return 1;

        if (maxMove == 0) return 0;

        if (dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];

        long long count = 0;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            count = (count + solve(m, n, maxMove - 1, ni, nj)) % MOD;
        }

        return dp[i][j][maxMove] = count;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};