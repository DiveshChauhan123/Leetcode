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
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // dp[i][prevIdx+1] = LIS length starting from i with prevIdx

        for (int i = n - 1; i >= 0; i--) {
            for (int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
                int notTake = dp[i + 1][prevIdx + 1];
                int take = 0;
                if (prevIdx == -1 || nums[i] > nums[prevIdx]) {
                    take = 1 + dp[i + 1][i + 1];  
                }
                dp[i][prevIdx + 1] = max(take, notTake);
            }
        }
        return dp[0][0]; // i=0, prevIdx=-1 -> stored at [0][0]
    }


};
