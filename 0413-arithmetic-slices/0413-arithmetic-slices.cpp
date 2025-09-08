class Solution {
public:
    int t[5001];

    int solve(vector<int>& nums, int i) {
        if (i < 2) return 0; // need at least 3 elements
        if (t[i] != -1) return t[i];

        int count = 0;
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            count = 1 + solve(nums, i-1); 
            // extend previous arithmetic slice
        }
        return t[i] = count;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        int ans = 0;

        for (int i = 2; i < n; i++) {
            ans += solve(nums, i); // accumulate all slices ending at i
        }

        return ans;
    }
};
