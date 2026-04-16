class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int usedMask, int target, int maxNum) {
        if (target <= 0) return false; // previous player already won
        
        if (dp.count(usedMask)) return dp[usedMask];

        for (int i = 1; i <= maxNum; i++) {
            int bit = (1 << i);

            // if number i is not used
            if ((usedMask & bit) == 0) {
                // if opponent loses → we win
                if (!solve(usedMask | bit, target - i, maxNum)) {
                    return dp[usedMask] = true;
                }
            }
        }

        return dp[usedMask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        // if total sum < desired → impossible
        if (sum < desiredTotal) return false;

        // if desiredTotal == 0 → already won
        if (desiredTotal == 0) return true;

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};