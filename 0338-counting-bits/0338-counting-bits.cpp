class Solution {
public:
    int solve(int i, vector<int>& dp) {
        if(i == 0) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = solve(i >> 1, dp) + (i & 1);
    }

    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);

        for(int i = 0; i <= n; i++) {
            dp[i] = solve(i, dp);
        }

        return dp;
    }
};