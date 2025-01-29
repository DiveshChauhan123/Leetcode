

class Solution {
public:
    long long solve(int index, vector<int>& nums, vector<vector<long long>>& dp, bool flag) {
        if (index >= nums.size()) return 0;
        if (dp[index][flag] != -1) return dp[index][flag];
        
        long long skip = solve(index + 1, nums, dp, flag);
        long long val = nums[index];
        if (!flag) val = -val;  // Alternate the sign based on the flag
        
        long long take = solve(index + 1, nums, dp, !flag) + val;
        
        return dp[index][flag] = max(take, skip);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return solve(0, nums, dp, true);
    }
};
