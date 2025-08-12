

class Solution {
public:
    const int MOD = 1e9 + 7;
    int t[305][301]; 

    int solve(vector<int> &nums, int index, int n) {
        if (n == 0) return 1;
        if (index >= nums.size()) return 0;

        if (t[index][n] != -1) return t[index][n];

        long long nottake = solve(nums, index + 1, n);
        long long take = 0;
        if (n - nums[index] >= 0)
            take = solve(nums, index + 1, n - nums[index]);

        return t[index][n] = (nottake + take) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> nums;
        memset(t, -1, sizeof(t));

        for (int num = 1; ; num++) {
            long long temp = pow(num, x);
            if (temp > n) break;
            nums.push_back((int)temp);
        }

        return solve(nums, 0, n);
    }
};

