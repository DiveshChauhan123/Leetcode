class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), maxLen = 0;
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                int j = i - dp[i - 1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = dp[i - 1] + 2 + (j > 0 ? dp[j - 1] : 0);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};
