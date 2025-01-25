class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, string& word, vector<vector<int>>& visited, int index) {
        if (index == word.size()) return true;

        visited[x][y] = 1;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() &&
                !visited[newX][newY] && board[newX][newY] == word[index]) {
                if (dfs(newX, newY, board, word, visited, index + 1)) {
                    return true;
                }
            }
        }

        visited[x][y] = 0; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<int>> visited(n, vector<int>(m, 0));
                    if (dfs(i, j, board, word, visited, 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
