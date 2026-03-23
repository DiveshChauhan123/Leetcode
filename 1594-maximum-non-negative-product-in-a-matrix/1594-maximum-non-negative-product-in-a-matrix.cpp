class Solution {
public:
    int n, m;
    typedef long long ll;

    vector<vector<pair<ll,ll>>> dp;
    vector<vector<bool>> vis;

    pair<ll,ll> solve(vector<vector<int>>& grid, int i, int j) {
        if (i == n - 1 && j == m - 1) {
            return {grid[i][j], grid[i][j]};
        }

        if (vis[i][j]) return dp[i][j];

        ll max_val = LLONG_MIN;
        ll min_val = LLONG_MAX;

        // move down
        if (i + 1 < n) {
            auto down = solve(grid, i + 1, j);
            ll downmax = down.first;
            ll downmin = down.second;

            max_val = max({max_val, grid[i][j] * downmax, grid[i][j] * downmin});
            min_val = min({min_val, grid[i][j] * downmax, grid[i][j] * downmin});
        }

        // move right
        if (j + 1 < m) {
            auto right = solve(grid, i, j + 1);
            ll rightmax = right.first;
            ll rightmin = right.second;

            max_val = max({max_val, grid[i][j] * rightmax, grid[i][j] * rightmin});
            min_val = min({min_val, grid[i][j] * rightmax, grid[i][j] * rightmin});
        }

        vis[i][j] = true;
        return dp[i][j] = {max_val, min_val};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<pair<ll,ll>>(m));
        vis.assign(n, vector<bool>(m, false));

        auto res = solve(grid, 0, 0);
        ll maxval = res.first;

        if (maxval < 0) return -1;
        return maxval % 1000000007;
    }
};