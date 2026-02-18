class Solution {
public:
    int n;
    vector<vector<long long>> dp;

    long long solve(vector<int>& nums, vector<int>& colors, int index, int prevColor, int prevRobbed) {
        if (index >= n) return 0;

        long long &res = dp[index][prevRobbed];
        if (res != -1) return res;

        // Option 1: Do not rob current house
        long long nottake = solve(nums, colors, index + 1, prevColor, 0);

        // Option 2: Rob current house (if allowed)
        long long take = 0;
        bool canRob = true;

        // If previous house was robbed and same color, cannot rob
        if (prevRobbed == 1 && prevColor == colors[index]) {
            canRob = false;
        }

        if (canRob) {
            take = nums[index] + solve(nums, colors, index + 1, colors[index], 1);
        }

        return res = max(take, nottake);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return solve(nums, colors, 0, -1, 0);
    }
};