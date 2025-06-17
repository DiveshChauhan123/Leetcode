class Solution {
public:
    double solve(int a, int b, vector<vector<double>> &dp) {
        if (a <= 0 && b > 0) return 1.0;
        if (a <= 0 && b <= 0) return 0.5;
        if (a > 0 && b <= 0) return 0.0;
        if (dp[a][b] != -1.0) return dp[a][b];

        double val = 0.0;
        val += solve(a - 4, b, dp);
        val += solve(a - 3, b - 1, dp);
        val += solve(a - 2, b - 2, dp);
        val += solve(a - 1, b - 3, dp);

        return dp[a][b] = val / 4.0;
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0; // optimization based on convergence

        int m = (n + 24) / 25; // convert to "units" of 25
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, -1.0));
        return solve(m, m, dp);
    }
};
