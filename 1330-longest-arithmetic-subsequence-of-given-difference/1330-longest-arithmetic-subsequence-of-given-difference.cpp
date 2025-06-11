class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        unordered_map<int, int> dp;
        int result = 0;

        for (int num : nums) {
            dp[num] = 1 + dp[num - difference];  // Extend previous valid subsequence
            result = max(result, dp[num]);
        }

        return result;
    }
};
