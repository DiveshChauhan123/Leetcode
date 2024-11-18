class Solution {
public:
    int solve(vector<vector<int>>& pairs, int i, int p, vector<vector<int>>& dp) {
        if (i >= pairs.size()) return 0;
        if (p != -1 && dp[i][p] != -1) return dp[i][p];
        
        int take = 0;
        if (p == -1 || pairs[i][0] > pairs[p][1]) {
            take = solve(pairs, i + 1, i, dp) + 1;
        }
        int skip = solve(pairs, i + 1, p, dp);
        
        if (p != -1) {
            dp[i][p] = max(take, skip);
        }
        
        return max(skip, take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(pairs, 0, -1, dp);
    }
};
