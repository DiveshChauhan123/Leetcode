class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs by their second element to make the chain conditions easier to handle
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = pairs.size();
        vector<int> dp(n, 1); // dp[i] will store the maximum chain length ending at pair i

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) { // Valid chain condition
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // The answer is the maximum value in dp array
        return *max_element(dp.begin(), dp.end());
    }
};
