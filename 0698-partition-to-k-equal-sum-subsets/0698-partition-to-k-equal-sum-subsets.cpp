class Solution {
public:
    int target;
    unordered_map<int, bool> dp;

    bool solve(vector<int>& nums, int mask, int currSum) {
        if (mask == (1 << nums.size()) - 1)
            return true;

        if (dp.count(mask))
            return dp[mask];

        for (int i = 0; i < nums.size(); i++) {
            if (!(mask & (1 << i))) { // not used
                if (currSum + nums[i] > target) continue;

                int newMask = mask | (1 << i);
                int newSum = (currSum + nums[i]) % target;

                if (solve(nums, newMask, newSum))
                    return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) return false;

        target = sum / k;

        return solve(nums, 0, 0);
    }
};