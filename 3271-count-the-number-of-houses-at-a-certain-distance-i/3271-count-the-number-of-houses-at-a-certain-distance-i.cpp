class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> ans(n+1, vector<int>(n+1, INT_MAX));
        for (int i = 1; i <= n; i++) ans[i][i] = 0;
        for (int i = 1; i < n; i++) {
            ans[i][i+1] = 1;
            ans[i+1][i] = 1;
        }
        ans[x][y] = 1;
        ans[y][x] = 1;

        // Floyd–Warshall
        for (int via = 1; via <= n; via++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (ans[i][via] < INT_MAX && ans[via][j] < INT_MAX)
                        ans[i][j] = min(ans[i][j], ans[i][via] + ans[via][j]);
                }
            }
        }

        // count pairs
        vector<int> result(n, 0);  // distances 1..n-1
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i==j)continue;
                int len = ans[i][j]-1;
                if (len>=0 && len<=n) result[len]++;
            }
        }
        return result;
    }
};
