class Solution {
public:
    int t[2501][2501]; // since nums.size() <= 2500

    int solve(int i, vector<int>& nums, int prevIdx) {
        if (i >= nums.size()) return 0;
        
        if (t[i][prevIdx + 1] != -1) return t[i][prevIdx + 1];
        
        int notTake = solve(i + 1, nums, prevIdx);
        int take = 0;
        if (prevIdx == -1 || nums[i] > nums[prevIdx]) {
            take = 1 + solve(i + 1, nums, i);
        }
        
        return t[i][prevIdx + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(0, nums, -1);
    }
};
