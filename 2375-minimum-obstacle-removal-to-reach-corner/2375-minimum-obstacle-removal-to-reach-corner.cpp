class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        while (!pq.empty()) {
            auto [currDist, pos] = pq.top();
            int x = pos.first;
            int y = pos.second;
            pq.pop();

            if (currDist > dist[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int newDist = currDist + (grid[newX][newY] == 1 ? 1 : 0);

                    if (newDist < dist[newX][newY]) {
                        dist[newX][newY] = newDist;
                        pq.push({newDist, {newX, newY}});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
