class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for (int i = n - 1; i >= 0; --i) {
            for (int flag = 0; flag < 2; ++flag) {
                long long skip = dp[i + 1][flag];
                long long val = (flag ? nums[i] : -nums[i]);
                long long take = dp[i + 1][!flag] + val;
                dp[i][flag] = max(take, skip);
            }
        }
        return dp[0][1];
    }
};

// long long solve(int index, vector<int>& nums, vector<vector<long long>>& dp, bool flag) {
//         if (index >= nums.size()) return 0;
//         if (dp[index][flag] != -1) return dp[index][flag];
        
//         long long skip = solve(index + 1, nums, dp, flag);
//         long long val = nums[index];
//         if (!flag) val = -val;  // Alternate the sign based on the flag
        
//         long long take = solve(index + 1, nums, dp, !flag) + val;
        
//         return dp[index][flag] = max(take, skip);
//     }
    
//     long long maxAlternatingSum(vector<int>& nums) {
//         vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
//         return solve(0, nums, dp, true);
//     }