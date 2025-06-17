class Solution {
public:
    double solve(int n, int k, int row, int column, vector<vector<vector<double>>> &t) {
        if (row < 0 || row >= n || column < 0 || column >= n) return 0.0;
        if (k == 0) return 1.0;

        if (t[k][row][column] != -1.0) return t[k][row][column];

        double ans = 0.0;
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < 8; ++i) {
            int x = row + dx[i];
            int y = column + dy[i];
            ans += solve(n, k - 1, x, y, t) / 8.0;
        }

        return t[k][row][column] = ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        // Initialize the 3D dp array with -1.0
        vector<vector<vector<double>>> t(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        return solve(n, k, row, column, t);
    }
};
