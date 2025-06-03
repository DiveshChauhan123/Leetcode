class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) return 0;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        queue<vector<int>> q;
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));

        q.push({0, 0, k});
        visited[0][0][k] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front(); q.pop();
                int x = curr[0], y = curr[1], obs = curr[2];

                for (int i = 0; i < 4; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a >= n || b < 0 || b >= m) continue;

                    if (a == n - 1 && b == m - 1) return steps + 1;

                    if (grid[a][b] == 0 && !visited[a][b][obs]) {
                        visited[a][b][obs] = true;
                        q.push({a, b, obs});
                    } else if (grid[a][b] == 1 && obs > 0 && !visited[a][b][obs - 1]) {
                        visited[a][b][obs - 1] = true;
                        q.push({a, b, obs - 1});
                    }
                }
            }
            steps++;
        }

        return -1; // Not reachable
    }
};
