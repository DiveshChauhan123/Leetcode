class Solution {
public:
    int solve(int i, vector<int>& dp, vector<int>& stonevalue) {
        if (i >= stonevalue.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int result = stonevalue[i] - solve(i + 1, dp, stonevalue);

        if (stonevalue.size() > i + 1) {
            result = max(result, stonevalue[i] + stonevalue[i + 1] - solve(i + 2, dp, stonevalue));
        }

        if (stonevalue.size() > i + 2) {
            result = max(result, stonevalue[i] + stonevalue[i + 1] + stonevalue[i + 2] - solve(i + 3, dp, stonevalue));  // ✅ fixed
        }

        return dp[i] = result;
    }

    string stoneGameIII(vector<int>& stonevalue) {
        vector<int> dp(stonevalue.size(), -1);
        int diff = solve(0, dp, stonevalue);

        if (diff < 0) return "Bob";
        else if (diff > 0) return "Alice";
        else return "Tie";
    }
};
