class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    int dp[101][201];  // dp[start][fuel]

    int solve(vector<int>& locations, int start, int finish, int fuel) {
        if (fuel < 0) return 0;
        if (dp[start][fuel] != -1) return dp[start][fuel];

        int ans = (start == finish) ? 1 : 0;

        for (int i = 0; i < n; i++) {
            if (i != start) {
                int cost = abs(locations[i] - locations[start]);
                if (fuel >= cost) {
                    ans = (ans + solve(locations, i, finish, fuel - cost)) % MOD;
                }
            }
        }
        return dp[start][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memset(dp, -1, sizeof(dp));
        return solve(locations, start, finish, fuel);
    }
};
