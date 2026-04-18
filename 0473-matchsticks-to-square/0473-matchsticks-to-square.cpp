class Solution {
public:
    bool backtrack(vector<int>& nums, vector<int>& sides, int index, int target) {
        if (index == nums.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + nums[index] <= target) {
                sides[i] += nums[index];

                if (backtrack(nums, sides, index + 1, target))
                    return true;

                sides[i] -= nums[index];
            }

            // 🔥 Pruning: avoid duplicate states
            if (sides[i] == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4 != 0) return false;

        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend()); // descending

        vector<int> sides(4, 0);

        return backtrack(matchsticks, sides, 0, target);
    }
};