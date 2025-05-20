class Solution {
public:
    int solve(vector<int>& days, int index, vector<int>& costs, vector<int>& dp) {
        if (index >= days.size()) return 0;
        if (dp[index] != -1) return dp[index];

        int x = INT_MAX;

        // Option 1: 1-day pass
        int i = index;
        while (i < days.size() && days[i] < days[index] + 1) i++;
        x = min(x, costs[0] + solve(days, i, costs, dp));

        // Option 2: 7-day pass
        i = index;
        while (i < days.size() && days[i] < days[index] + 7) i++;
        x = min(x, costs[1] + solve(days, i, costs, dp));

        // Option 3: 30-day pass
        i = index;
        while (i < days.size() && days[i] < days[index] + 30) i++;
        x = min(x, costs[2] + solve(days, i, costs, dp));

        return dp[index] = x;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return solve(days, 0, costs, dp);
    }
};
