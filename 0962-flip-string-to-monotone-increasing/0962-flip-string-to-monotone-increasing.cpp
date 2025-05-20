class Solution {
public:
    int solve(string &s, int curr, int prev, vector<vector<int>>& dp) {
        if (curr >= s.length()) return 0;
        if (dp[curr][prev] != -1) return dp[curr][prev];

        int flip = INT_MAX, notflip = INT_MAX;

        if (s[curr] == '0') {
            if (prev == 0) {
                // Can keep 0 or flip to 1
                notflip = solve(s, curr + 1, 0, dp);
                flip = 1 + solve(s, curr + 1, 1, dp);
            } else {
                // Only option is to flip to 1 (to maintain monotonic increasing)
                flip = 1 + solve(s, curr + 1, 1, dp);
            }
        } else { // s[curr] == '1'
            if (prev == 0) {
                // Can keep 1 or flip to 0
                notflip = solve(s, curr + 1, 1, dp);
                flip = 1 + solve(s, curr + 1, 0, dp);
            } else {
                // Must keep 1 to maintain increasing
                notflip = solve(s, curr + 1, 1, dp);
            }
        }

        return dp[curr][prev] = min(flip, notflip);
    }

    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(s, 0, 0, dp);  // Start with previous being 0
    }
};
