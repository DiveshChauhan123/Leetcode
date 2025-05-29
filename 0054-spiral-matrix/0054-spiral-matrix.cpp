class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<int> result;
    
    // Directions: right, down, left, up
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int r = 0, c = 0, d = 0;
    for (int i = 0; i < m * n; ++i) {
        result.push_back(matrix[r][c]);
        visited[r][c] = true;
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
            r = nr;
            c = nc;
        } else {
            d = (d + 1) % 4;
            r += dr[d];
            c += dc[d];
        }
    }
    return result;
    }
};